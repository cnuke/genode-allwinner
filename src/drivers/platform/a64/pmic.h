/*
 * \brief  Driver for A64 power management IC
 * \author Norman Feske
 * \date   2021-11-08
 */

/*
 * Copyright (C) 2021 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#ifndef _SRC__DRIVERS__PLATFORM__A64__PMIC_H_
#define _SRC__DRIVERS__PLATFORM__A64__PMIC_H_

#include <os/attached_mmio.h>
#include <power.h>
#include <rsb.h>
#include <timer_session/connection.h>

namespace Driver { struct Pmic; }


struct Driver::Pmic : private Noncopyable
{
	Genode::Env &_env;
	Powers      &_powers;

	Rsb _rsb;

	Timer::Connection _timer;

	enum class Bit_op : uint8_t { SET, CLEAR };
	static void change_bit(Rsb &rsb, Rsb::Reg reg, uint8_t bit, Bit_op op)
	{
		uint8_t v = rsb.read_byte(reg);
		using namespace Genode;

		if (op == Bit_op::SET) v |= (uint8_t) (1u << bit);
		else                   v &= (uint8_t)~(1u << bit);

		rsb.write_byte(reg, v);
	}

	template <uint16_t LDO_REG, uint8_t ON_VAL, uint8_t OFF_VAL,
	          uint16_t CTL_REG, uint8_t BIT>
	struct Set_enable_ldo : Power
	{
		Rsb &_rsb;

		Set_enable_ldo(Powers &powers, Power::Name const &name, Rsb &rsb)
		: Power(powers, name), _rsb(rsb) { }

		void _on() override
		{
			_rsb.write_byte(Rsb::Reg { LDO_REG }, ON_VAL);
			change_bit(_rsb, Rsb::Reg { CTL_REG }, BIT, Bit_op::SET);
		}

		void _off() override
		{
			change_bit(_rsb, Rsb::Reg { CTL_REG }, BIT, Bit_op::CLEAR);
			_rsb.write_byte(Rsb::Reg { LDO_REG }, OFF_VAL);
		}
	};

	struct Aldo1 : Set_enable_ldo<0x28, 0x0b, 0x17, 0x13, 5>
	{
		Aldo1(Powers &power, Power::Name const &name, Rsb &rsb)
		: Set_enable_ldo(power, name, rsb) { }
	};

	struct Dldo3 : Set_enable_ldo<0x17, 0x15, 0x15, 0x12, 5>
	{
		Dldo3(Powers &power, Power::Name const &name, Rsb &rsb)
		: Set_enable_ldo(power, name, rsb) { }
	};

	struct Eldo3 : Set_enable_ldo<0x1b, 0x16, 0x0, 0x12, 2>
	{
		Eldo3(Powers &power, Power::Name const &name, Rsb &rsb)
		: Set_enable_ldo(power, name, rsb) { }
	};

	struct Csi_power : Power
	{
		Rsb    &_rsb;
		Powers &_powers;

		Aldo1 aldo1 { _powers, "pmic-aldo1", _rsb };
		Dldo3 dldo3 { _powers, "pmic-dldo3", _rsb };
		Eldo3 eldo3 { _powers, "pmic-eldo3", _rsb };

		Timer::Connection &_timer;

		Csi_power(Powers &powers, Power::Name const &name, Rsb &rsb, Timer::Connection &timer)
		: Power(powers, name), _rsb(rsb), _powers(powers), _timer(timer) { }

		void _on()  override
		{
			aldo1._on();
			_timer.usleep(50);

			eldo3._on();
			_timer.usleep(10);

			dldo3._on();
			_timer.usleep(10);
		}

		void _off() override
		{
			dldo3._off();
			eldo3._off();
			aldo1._off();
		}
	};

	Csi_power _csi_power { _powers, "pmic-csi", _rsb, _timer };

	struct Gpio_ldo : Power
	{
		Rsb &_rsb;

		Rsb::Reg const _reg;

		Gpio_ldo(Powers &powers, Power::Name const &name, Rsb &rsb, Rsb::Reg reg)
		:
			Power(powers, name), _rsb(rsb), _reg(reg)
		{ }

		void _on()  override { _rsb.write_byte(_reg, 3); }
		void _off() override { _rsb.write_byte(_reg, 7); }
	};

	Gpio_ldo gpio0_ldo { _powers, "pmic-gpio0", _rsb, Rsb::Reg { 0x90 } };

	Pmic(Genode::Env &env, Powers &powers)
	:
		_env(env), _powers(powers), _rsb(env), _timer(env)
	{ }
};

#endif /* _SRC__DRIVERS__PLATFORM__A64__PMIC_H_ */

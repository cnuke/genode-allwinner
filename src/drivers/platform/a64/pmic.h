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

	static void set_bit(Rsb &rsb, Rsb::Reg reg, uint8_t bit, bool value)
	{
		uint8_t v = rsb.read_byte(reg);
		using namespace Genode;

		if (value) v |= (uint8_t) (1u << bit);
		else       v &= (uint8_t)~(1u << bit);

		rsb.write_byte(reg, v);
	}

	struct Aldo1 : Power
	{
		Rsb &_rsb;

		Aldo1(Powers &powers, Power::Name const &name, Rsb &rsb)
		: Power(powers, name), _rsb(rsb) { }

		void _on()  override
		{
			_rsb.write_byte(Rsb::Reg { 0x28 }, 0x0b);
			set_bit(_rsb, Rsb::Reg { 0x13 }, 5, true);
		}

		void _off() override
		{
			set_bit(_rsb, Rsb::Reg { 0x13 }, 5, false);
			_rsb.write_byte(Rsb::Reg { 0x28 }, 0x17);
		}
	};

	Aldo1 aldo1 { _powers, "pmic-aldo1", _rsb };

	struct Dldo3 : Power
	{
		Rsb &_rsb;

		Dldo3(Powers &powers, Power::Name const &name, Rsb &rsb)
		: Power(powers, name), _rsb(rsb) { }

		void _on()  override
		{
			_rsb.write_byte(Rsb::Reg { 0x17 }, 0x15);
			set_bit(_rsb, Rsb::Reg { 0x12 }, 5, true);
		}

		void _off() override
		{
			set_bit(_rsb, Rsb::Reg { 0x12 }, 5, false);
			_rsb.write_byte(Rsb::Reg { 0x17 }, 0x15);
		}
	};

	Dldo3 dldo3 { _powers, "pmic-dldo3", _rsb };

	struct Eldo3 : Power
	{
		Rsb &_rsb;

		Eldo3(Powers &powers, Power::Name const &name, Rsb &rsb)
		: Power(powers, name), _rsb(rsb) { }

		void _on()  override
		{
			_rsb.write_byte(Rsb::Reg { 0x1b }, 0x16);
			set_bit(_rsb, Rsb::Reg { 0x12 }, 2, true);
		}

		void _off() override
		{
			set_bit(_rsb, Rsb::Reg { 0x12 }, 2, false);
			_rsb.write_byte(Rsb::Reg { 0x1b }, 0x0);
		}
	};

	Eldo3 eldo3 { _powers, "pmic-eldo3", _rsb };

	struct Csi_power : Power
	{
		Rsb &_rsb;

		Timer::Connection &_timer;

		Csi_power(Powers &powers, Power::Name const &name, Rsb &rsb, Timer::Connection &timer)
		: Power(powers, name), _rsb(rsb), _timer(timer) { }

		void _on()  override
		{
			// Aldo1
			_rsb.write_byte(Rsb::Reg { 0x28 }, 0x0b);
			set_bit(_rsb, Rsb::Reg { 0x13 }, 5, true);

			_timer.usleep(50);

			// Eldo3
			_rsb.write_byte(Rsb::Reg { 0x1b }, 0x16);
			set_bit(_rsb, Rsb::Reg { 0x12 }, 2, true);

			_timer.usleep(10);

			// Dldo3
			_rsb.write_byte(Rsb::Reg { 0x17 }, 0x15);
			set_bit(_rsb, Rsb::Reg { 0x12 }, 5, true);

			_timer.usleep(10);
		}

		void _off() override
		{
			// Dldo3
			set_bit(_rsb, Rsb::Reg { 0x12 }, 5, false);
			_rsb.write_byte(Rsb::Reg { 0x17 }, 0x15);

			// Eldo3
			set_bit(_rsb, Rsb::Reg { 0x12 }, 2, false);
			_rsb.write_byte(Rsb::Reg { 0x1b }, 0x0);

			// Aldo1
			set_bit(_rsb, Rsb::Reg { 0x13 }, 5, false);
			_rsb.write_byte(Rsb::Reg { 0x28 }, 0x17);
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

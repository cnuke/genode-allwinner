/*
 * \brief  Platform driver for Allwinner A64
 * \author Norman Feske
 * \date   2021-11-08
 */

/*
 * Copyright (C) 2020 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#include <base/attached_io_mem_dataspace.h>
#include <base/component.h>

#include <r_prcm.h>
#include <ccu.h>
#include <pmic.h>
#include <common.h>
#include <scp.h>


static Genode::uint32_t crc32(void const * const buf, Genode::size_t size)
{
	using namespace Genode;

	uint8_t const *p = static_cast<uint8_t const*>(buf);
	uint32_t crc = ~0U;

	while (size--) {
		crc ^= *p++;
		for (uint32_t j = 0; j < 8; j++)
			crc = (-int32_t(crc & 1) & 0xedb88320) ^ (crc >> 1);
	}

	return crc ^ ~0U;
}


namespace Driver { struct Main; };

struct Driver::Main
{
	Env                  & _env;
	Attached_rom_dataspace _config_rom     { _env, "config"        };
	Common                 _common         { _env, _config_rom     };
	Signal_handler<Main>   _config_handler { _env.ep(), *this,
	                                         &Main::_handle_config };
	void _handle_config();

	Attached_io_mem_dataspace _sid_chip_id { _env, 0x01C14200, 16 };
	void _generate_mac_address();

	Fixed_clock _osc_24m_clk { _common.devices().clocks(), "osc24M",
	                           Clock::Rate { 24*1000*1000 } };
	Fixed_clock _dummy_clk   { _common.devices().clocks(), "dummy",
	                           Clock::Rate { 1000 } };

	R_prcm _r_prcm { _env, _common.devices().clocks(), _osc_24m_clk };
	Ccu    _ccu    { _env, _common.devices().clocks(),
	                 _common.devices().resets(), _osc_24m_clk };

	Scp::Driver _scp { _env, _ccu._mbox_rst, _ccu._mbox_gate };

	Pmic _pmic { _scp.local_connection, _common.devices().powers() };

	void _load_scp_firmware();

	Main(Genode::Env & env) : _env(env)
	{
		_config_rom.sigh(_config_handler);
		_handle_config();
		_generate_mac_address();
		_load_scp_firmware();
		_common.announce_service();
	}
};


void Driver::Main::_handle_config()
{
	_config_rom.update();
	_common.handle_config(_config_rom.xml());
}


void Driver::Main::_generate_mac_address()
{
	/* use the same approach as U-Boot to generate a MAC address */

	uint32_t const *chip_id = _sid_chip_id.local_addr<uint32_t>();
	uint32_t const  crc_value = crc32(&chip_id[1], 12);

	uint8_t mac_addr[6] = { };
	mac_addr[0] = 0x02;
	mac_addr[1] = static_cast<uint8_t>(chip_id[0] >>  0) & 0xffu;
	mac_addr[2] = static_cast<uint8_t>(crc_value  >> 24) & 0xffu;
	mac_addr[3] = static_cast<uint8_t>(crc_value  >> 16) & 0xffu;
	mac_addr[4] = static_cast<uint8_t>(crc_value  >>  8) & 0xffu;
	mac_addr[5] = static_cast<uint8_t>(crc_value  >>  0) & 0xffu;

	log("MAC address: ",
		Hex(mac_addr[0], Hex::OMIT_PREFIX), ":",
		Hex(mac_addr[1], Hex::OMIT_PREFIX), ":",
		Hex(mac_addr[2], Hex::OMIT_PREFIX), ":",
		Hex(mac_addr[3], Hex::OMIT_PREFIX), ":",
		Hex(mac_addr[4], Hex::OMIT_PREFIX), ":",
		Hex(mac_addr[5], Hex::OMIT_PREFIX));
}


void Driver::Main::_load_scp_firmware()
{
	char const *firmware[] = {

		/* testing ground for SCP firmware customizations */
	};

	for (char const *command : firmware) {
		auto response = _scp.local_connection.execute(command);

		if (response.length() > 1)
			log("SCP: ", response);
	}
}


void Component::construct(Genode::Env &env) { static Driver::Main main(env); }

/**
 * \brief  Acquire MAC address
 * \author Josef Soentgen
 * \date   2023-04-13
 */

/*
 * Copyright (C) 2023 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

/* Genode includes */
#include <net/mac_address.h>

/* DDE Linux includes */
#include <lx_kit/env.h>

using namespace Genode;


template <typename FN>
static void acquire_mac_address(FN const &fn)
{
	Lx_kit::env().platform.with_xml([&] (Xml_node const &xml) {

		xml.for_each_sub_node("device", [&] (Xml_node const &node) {
			if (node.attribute_value("name", String<17>()) != "mac_address-wifi")
				return;

			node.with_sub_node("property", [&] (Xml_node const &sub_node) {
				if (sub_node.attribute_value("name", String<12>()) != "mac_address")
					return;

				Net::Mac_address const mac_address =
					sub_node.attribute_value("value", Net::Mac_address());

				if (mac_address != Net::Mac_address())
					fn(mac_address);
			},
			[&] { warning("mac_address-wifi node invalid"); });
		});
	});
}


extern "C" char const *lx_emul_get_mac_addr(void)
{
	static char addr_buffer[6] = { 0xf2, 0x47, 0x4e, 0x44, 0x50, 0x50 };

	if (addr_buffer[0] == 0xf2)
		acquire_mac_address([&] (Net::Mac_address const &mac_addr) {
			mac_addr.copy(addr_buffer);
		});

	if (addr_buffer[0] == 0xf2) {
		Genode::warning("driver will use random MAC address");
		return nullptr;
	}

	return addr_buffer;
}

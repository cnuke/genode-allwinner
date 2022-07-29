/*
 * \brief  PinePhone camera driver port
 * \author Josef Soentgen
 * \date   2022-07-29
 */

/*
 * Copyright (C) 2022 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

/* Genode includes */
#include <base/attached_rom_dataspace.h>
#include <base/component.h>
#include <base/env.h>

#include <lx_emul/init.h>
#include <lx_emul/shared_dma_buffer.h>
#include <lx_kit/env.h>
#include <lx_kit/init.h>
#include <lx_user/io.h>

#include "lx_user.h"
#include "gui.h"

using namespace Genode;

/* initialized with default values by lx_user */
extern struct lx_user_config_t lx_user_config;


struct Main : private Entrypoint::Io_progress_handler
{
	Env                  & env;
	Attached_rom_dataspace dtb_rom        { env, "dtb"           };
	Signal_handler<Main>   signal_handler { env.ep(), *this,
	                                        &Main::handle_signal };
	Sliced_heap            sliced_heap    { env.ram(), env.rm()  };

	Attached_rom_dataspace config_rom     { env, "config"        };

	void _update_config()
	{
		if (!config_rom.valid())
			return;

		config_rom.update();
		Xml_node const config = config_rom.xml();

		lx_user_config.width = config.attribute_value("width",  lx_user_config.width);
		if (lx_user_config.width > MAX_WIDTH) {
			lx_user_config.width = MAX_WIDTH;
			warning("limit width to ", lx_user_config.width);
		}
		lx_user_config.height = config.attribute_value("height", lx_user_config.height);
		if (lx_user_config.height > MAX_HEIGHT) {
			lx_user_config.height = MAX_HEIGHT;
			warning("limit height to ", lx_user_config.height);
		}
		lx_user_config.fps = config.attribute_value("fps",    lx_user_config.fps);
		if (lx_user_config.fps > MAX_FPS) {
			lx_user_config.fps = MAX_FPS;
			warning("limit fps to ", lx_user_config.fps);
		}

		using Format = String<8>;
		Format format { };
		format = config.attribute_value("format", Format("yuv"));
		if      (format == "yuv")   lx_user_config.format = 0;
		// else if (format == "bggr8") lx_user_config.format = 1;
		else warning("invalid format selection, using yuv");

		using Camera = String<16>;
		Camera cam { };
		cam = config.attribute_value("camera", Camera("front"));
		if      (cam == "front") lx_user_config.camera = 0;
		else if (cam == "rear")  lx_user_config.camera = 1;
		else warning("invalid camera selection, using front camera");

		lx_user_config.valid = true;

		log("Use ", cam, " camera configuration: ",
		    lx_user_config.width, "x", lx_user_config.height, "@",
		    lx_user_config.fps, " (", format, ")");
	}

	/**
	 * Entrypoint::Io_progress_handler
	 */
	void handle_io_progress() override
	{
	}

	void handle_signal()
	{
		lx_user_handle_io();
		Lx_kit::env().scheduler.schedule();
	}

	Main(Env & env) : env(env)
	{
		Lx_kit::initialize(env);
		env.exec_static_constructors();

		_update_config();

		genode_gui_init(genode_env_ptr(env),
		                genode_allocator_ptr(sliced_heap));

		lx_emul_start_kernel(dtb_rom.local_addr<void>());

		env.ep().register_io_progress_handler(*this);
	}
};


void Component::construct(Env & env) { static Main main(env); }

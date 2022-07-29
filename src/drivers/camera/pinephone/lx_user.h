/*
 * \brief  Configuration for lx_user task
 * \author Josef Soentgen
 * \date   2022-09-27
 */

/*
 * Copyright (C) 2022 Genode Labs GmbH
 *
 * This file is distributed under the terms of the GNU General Public License
 * version 2.
 */

#ifdef __cplusplus
extern "C" {
#endif

enum {
	MAX_WIDTH  = 1280,
	MAX_HEIGHT = 720,
	MAX_FPS    = 30,
};

struct lx_user_config_t
{
	unsigned width;
	unsigned height;
	unsigned fps;
	/* YUV420 = 0, SBGGR8 = 1 */
	unsigned format;
	/* front = 0, rear = 1 */
	unsigned camera;

	unsigned valid;
};


#ifdef __cplusplus
}
#endif

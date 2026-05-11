/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:19:50 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/02 21:00:53 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "rendering/texture.h"
#include "utils/utils.h"
#include <unistd.h>
#include <string.h>

int	load_anim_frames(t_context *ctxt)
{
	int			i;
	const char	*paths[] = {
		FIRE_0, FIRE_1, FIRE_2, FIRE_3, FIRE_4, FIRE_5, FIRE_6, FIRE_7};

	ctxt->game->map_info.anim_frame_count = 8;
	ctxt->game->map_info.anim_frames = c_alloc(8, sizeof(t_texture));
	if (!ctxt->game->map_info.anim_frames)
		return (ERROR);
	i = 0;
	while (i < 8)
	{
		if (load_xpm_into_texture(ctxt->mlx, paths[i],
				&ctxt->game->map_info.anim_frames[i]) == ERROR)
		{
			basic_error("Failed to load animation frame");
			return (ERROR);
		}
		if (!ctxt->game->map_info.anim_frames[i].addr)
		{
			basic_error("Animation frame addr is NULL");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

static void	start_background_music(t_context *ctxt)
{
	char	*cmd;

	if (strstr(ctxt->game->map_info.filename, "end.cub"))
		cmd = "while true; do afplay -v 0.5 assets/sounds/Piano.wav "
			"2>/dev/null; done";
	else
		cmd = "while true; do afplay -v 0.5 assets/sounds/Hal3.wav "
			"2>/dev/null; done";
	ctxt->mlx->music_pid = fork();
	if (ctxt->mlx->music_pid == 0)
	{
		setpgid(0, 0);
		execl("/bin/sh", "sh", "-c", cmd, NULL);
		exit(0);
	}
}

static void	play_intro_sound(t_context *ctxt)
{
	if (!strstr(ctxt->game->map_info.filename, "end.cub"))
		return ;
	ctxt->mlx->intro_sound_pid = fork();
	if (ctxt->mlx->intro_sound_pid == 0)
	{
		setpgid(0, 0);
		execl("/bin/sh", "sh", "-c",
			"afplay assets/sounds/travel.wav 2>/dev/null", NULL);
		exit(0);
	}
}

static int	init_mlx_image(t_context *ctxt, int screen_w, int screen_h)
{
	ctxt->mlx->img = mlx_new_image(ctxt->mlx->mlx, screen_w, screen_h);
	if (!ctxt->mlx->img)
		return (ERROR);
	ctxt->mlx->addr = mlx_get_data_addr(ctxt->mlx->img,
			&ctxt->mlx->bits_per_pixel, &ctxt->mlx->line_length,
			&ctxt->mlx->endian);
	if (!ctxt->mlx->addr)
		return (ERROR);
	ctxt->mlx->screen_width = screen_w;
	ctxt->mlx->screen_height = screen_h;
	ctxt->game->map_info.anim_frame_count = 0;
	ctxt->game->map_info.anim_curr_frame = 0;
	ctxt->mlx->hotbar_item_img = mlx_xpm_file_to_image(ctxt->mlx->mlx,
			"assets/textures/diamond.xpm", &ctxt->mlx->hotbar_item_w,
			&ctxt->mlx->hotbar_item_h);
	if (ctxt->mlx->hotbar_item_img)
		ctxt->mlx->hotbar_item_addr = mlx_get_data_addr(
				ctxt->mlx->hotbar_item_img, &screen_w, &screen_h, &screen_w);
	return (SUCCESS);
}

/* Initialize MLX: connection, window, image and get screen dimensions */
int	initialize_mlx(char *filename, t_context *ctxt)
{
	ctxt->mlx->mlx = mlx_init();
	if (!ctxt->mlx->mlx)
		return (ERROR);
	ctxt->mlx->mlx_win = mlx_new_window(ctxt->mlx->mlx, WDW_WIDTH, WDW_HEIGHT,
			filename);
	if (!ctxt->mlx->mlx_win)
		return (ERROR);
	if (init_mlx_image(ctxt, WDW_WIDTH, WDW_HEIGHT) == ERROR)
		return (ERROR);
	start_background_music(ctxt);
	play_intro_sound(ctxt);
	return (SUCCESS);
}

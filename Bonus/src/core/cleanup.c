/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:08:44 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/02 21:00:53 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "types.h"
#include <stdlib.h>
#include <signal.h>

/* Free 2D map array by freeing each row then the array itself */
void	free_map_grid(char **map, int height)
{
	int	r;

	if (!map)
		return ;
	r = 0;
	while (r < height)
	{
		free(map[r]);
		r++;
	}
	free(map);
}

/* Free MLX resources: image, window, display and MLX pointer */
void	free_mlx(t_context *ctxt)
{
	if (ctxt->mlx->music_pid > 0)
	{
		kill(-ctxt->mlx->music_pid, SIGKILL);
		kill(ctxt->mlx->music_pid, SIGKILL);
	}
	if (ctxt->mlx->intro_sound_pid > 0)
	{
		kill(-ctxt->mlx->intro_sound_pid, SIGKILL);
		kill(ctxt->mlx->intro_sound_pid, SIGKILL);
	}
	if (ctxt->mlx->hotbar_item_img)
		mlx_destroy_image(ctxt->mlx->mlx, ctxt->mlx->hotbar_item_img);
	if (ctxt->mlx->img)
		mlx_destroy_image(ctxt->mlx->mlx, ctxt->mlx->img);
	if (ctxt->mlx->mlx_win)
		mlx_destroy_window(ctxt->mlx->mlx, ctxt->mlx->mlx_win);
	if (ctxt->mlx->mlx)
		free(ctxt->mlx->mlx);
}

/* Frees textures from game structure */
static void	free_game_textures(t_context *ctxt)
{
	int	i;

	if (!ctxt->game || !ctxt->mlx || !ctxt->mlx->mlx)
		return ;
	i = 0;
	while (i < 4)
	{
		if (ctxt->game->map_info.textures[i].img)
			destroy_texture(ctxt->mlx, &ctxt->game->map_info.textures[i]);
		i++;
	}
	i = 0;
	while (i < ctxt->game->map_info.anim_frame_count && i < 8)
	{
		if (ctxt->game->map_info.anim_frames
			&& ctxt->game->map_info.anim_frames[i].img)
			destroy_texture(ctxt->mlx, &ctxt->game->map_info.anim_frames[i]);
		i++;
	}
	if (ctxt->game->map_info.door_texture.img)
		destroy_texture(ctxt->mlx, &ctxt->game->map_info.door_texture);
}

void	cleanup_context(t_context *ctxt)
{
	if (!ctxt)
		return ;
	if (ctxt->mlx && ctxt->game)
		free_game_textures(ctxt);
	if (ctxt->mlx)
	{
		free_mlx(ctxt);
		free(ctxt->mlx);
		ctxt->mlx = NULL;
	}
	if (ctxt->game)
	{
		free_game_maps(ctxt);
		free(ctxt->game);
		ctxt->game = NULL;
	}
	if (ctxt->player)
	{
		free(ctxt->player);
		ctxt->player = NULL;
	}
	free(ctxt);
}

/* Free any data in mlx_structure */
int	free_structs(t_context *ctxt)
{
	cleanup_context(ctxt);
	exit(SUCCESS);
}

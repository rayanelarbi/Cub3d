/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:30:00 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 16:30:00 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "types.h"
#include <stdlib.h>

/* Free animation frame paths */
static void	free_anim_frame_paths(t_map_info *mi)
{
	int	i;

	if (!mi->anim_frames)
		return ;
	i = 0;
	while (i < mi->anim_frame_count)
	{
		if (mi->anim_frames[i].path)
		{
			free(mi->anim_frames[i].path);
			mi->anim_frames[i].path = NULL;
		}
		i++;
	}
	free(mi->anim_frames);
	mi->anim_frames = NULL;
}

/* Free texture paths */
static void	free_texture_paths(t_map_info *mi)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (mi->textures[i].path)
		{
			free(mi->textures[i].path);
			mi->textures[i].path = NULL;
		}
	}
}

/* Free any strings in a s_map_info */
void	free_map_info(t_map_info *mi)
{
	if (!mi)
		return ;
	if (mi->filename)
	{
		free(mi->filename);
		mi->filename = NULL;
	}
	if (mi->door_texture.path)
	{
		free(mi->door_texture.path);
		mi->door_texture.path = NULL;
	}
	free_anim_frame_paths(mi);
	free_texture_paths(mi);
	mi->floor_color = 0;
	mi->ceiling_color = 0;
}

/* Frees maps from game structure */
void	free_game_maps(t_context *ctxt)
{
	if (!ctxt->game)
		return ;
	free_map_grid(ctxt->game->map, ctxt->game->height);
	if (ctxt->game->door_open_state)
		free_map_grid(ctxt->game->door_open_state, ctxt->game->height);
	free_map_info(&ctxt->game->map_info);
}

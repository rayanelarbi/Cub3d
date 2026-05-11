/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:30:00 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/02 10:03:31 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "types.h"
#include <stdlib.h>	

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
	free_map_info(&ctxt->game->map_info);
}

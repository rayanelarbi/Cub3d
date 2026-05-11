/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:00:00 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 18:00:00 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "config/constants.h"
#include "utils/utils.h"
#include "game/game.h"

/* Helper to set direction from lookup table */
void	set_direction_from_table(t_player *pl, int index)
{
	static const t_vec	dirs[4] = {
	{0.0f, -1.0f}, {0.0f, 1.0f}, {-1.0f, 0.0f}, {1.0f, 0.0f}};

	pl->dir.x = dirs[index].x;
	pl->dir.y = dirs[index].y;
}

/* Set player initial direction vector based on map starting char */
void	init_player_direction(t_context *ctxt)
{
	static const char	orientations[4] = {'N', 'S', 'W', 'E'};
	int					i;

	i = 0;
	while (i < 4)
	{
		if (ctxt->game->starting_direction == orientations[i])
		{
			set_direction_from_table(ctxt->player, i);
			return ;
		}
		i++;
	}
}

/* Initialize player position, direction, plane, speeds and mouse */
void	init_player_params(t_context *ctxt)
{
	ctxt->player->pos.x = ctxt->game->starting_position.x;
	ctxt->player->pos.y = ctxt->game->starting_position.y;
	init_player_direction(ctxt);
	ctxt->player->plane.x = -ctxt->player->dir.y * 0.66f;
	ctxt->player->plane.y = ctxt->player->dir.x * 0.66f;
	ctxt->player->move_speed = 0.05f;
	ctxt->player->rot_speed = 0.03f;
	ctxt->player->mouse_x = -1;
	ctxt->player->mouse_y = -1;
	ctxt->player->mouse_sensitivity = 0.001f;
}

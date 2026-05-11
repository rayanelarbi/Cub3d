/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/02 21:00:53 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "game/game.h"
#include <string.h>

static void	search_from_start(t_context *ctxt, int curr_x, int curr_y)
{
	int	y;
	int	x;

	y = 0;
	while (y <= curr_y)
	{
		x = 0;
		while (x < ctxt->game->width)
		{
			if (y == curr_y && x >= curr_x)
				return ;
			if (ctxt->game->map[y][x] == 'D')
			{
				ctxt->player->pos.x = x + 0.5;
				ctxt->player->pos.y = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	find_next_portal(t_context *ctxt, int curr_x, int curr_y)
{
	int	y;
	int	x;

	y = curr_y;
	while (y < ctxt->game->height)
	{
		if (y == curr_y)
			x = curr_x + 1;
		else
			x = 0;
		while (x < ctxt->game->width)
		{
			if (ctxt->game->map[y][x] == 'D')
			{
				ctxt->player->pos.x = x + 0.5;
				ctxt->player->pos.y = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
	search_from_start(ctxt, curr_x, curr_y);
}

void	check_portal_sound(t_context *ctxt)
{
	int				px;
	int				py;
	static int		was_on_portal = 0;

	if (!strstr(ctxt->game->map_info.filename, "end.cub"))
		return ;
	px = (int)ctxt->player->pos.x;
	py = (int)ctxt->player->pos.y;
	if (ctxt->game->map[py][px] == 'D')
	{
		if (!was_on_portal)
		{
			system("afplay assets/sounds/portal.wav 2>/dev/null &");
			was_on_portal = 1;
		}
	}
	else
		was_on_portal = 0;
}

void	check_teleport(t_context *ctxt)
{
	int				px;
	int				py;
	static int		was_on_portal = 0;

	if (!strstr(ctxt->game->map_info.filename, "end.cub"))
		return ;
	px = (int)ctxt->player->pos.x;
	py = (int)ctxt->player->pos.y;
	if (ctxt->game->map[py][px] == 'D' && !was_on_portal)
	{
		find_next_portal(ctxt, px, py);
		was_on_portal = 1;
	}
	else if (ctxt->game->map[py][px] != 'D')
		was_on_portal = 0;
}

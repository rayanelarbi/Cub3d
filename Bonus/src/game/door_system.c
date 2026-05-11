/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_system.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:00:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/02 21:00:53 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

/* Allocate a door state row for the given map row */
static char	*allocate_door_row(char *map_row)
{
	int		len;
	int		j;
	char	*row;

	len = 0;
	while (map_row && map_row[len])
		len++;
	row = malloc(sizeof(char) * (len + 1));
	if (!row)
		return (NULL);
	j = 0;
	while (j < len)
	{
		row[j] = '0';
		j++;
	}
	row[j] = '\0';
	return (row);
}

/* Initialize door open state tracking */
void	init_doors(t_game *game)
{
	int	i;

	if (!game || !game->map)
		return ;
	game->door_open_state = malloc(sizeof(char *) * (game->height + 1));
	if (!game->door_open_state)
		return ;
	i = 0;
	while (i < game->height)
	{
		game->door_open_state[i] = allocate_door_row(game->map[i]);
		if (!game->door_open_state[i])
		{
			while (--i >= 0)
				free(game->door_open_state[i]);
			free(game->door_open_state);
			game->door_open_state = NULL;
			return ;
		}
		i++;
	}
	game->door_open_state[i] = NULL;
}

/* Check if player is close to door position */
static int	is_player_near_door(t_context *ctxt, int door_x, int door_y)
{
	double	dx;
	double	dy;
	double	distance;

	dx = ctxt->player->pos.x - (door_x + 0.5);
	dy = ctxt->player->pos.y - (door_y + 0.5);
	distance = sqrt(dx * dx + dy * dy);
	return (distance < 1.5);
}

/* Toggle door - not used in simple system */
void	toggle_door(t_context *ctxt)
{
	(void)ctxt;
}

/* Check if door at position should block raycasting */
int	should_door_block(t_context *ctxt, int x, int y)
{
	int	is_near;

	if (!ctxt || !ctxt->game || !ctxt->game->map)
		return (0);
	if (y < 0 || y >= ctxt->game->height || x < 0)
		return (0);
	if (!ctxt->game->map[y] || ctxt->game->map[y][x] != 'D')
		return (0);
	is_near = is_player_near_door(ctxt, x, y);
	if (ctxt->game->door_open_state && ctxt->game->door_open_state[y]
		&& ctxt->game->door_open_state[y][x] == '0' && is_near)
	{
		ctxt->game->door_open_state[y][x] = '1';
		if (!strstr(ctxt->game->map_info.filename, "end.cub"))
			system("afplay assets/sounds/open1.wav 2>/dev/null &");
	}
	else if (ctxt->game->door_open_state && ctxt->game->door_open_state[y]
		&& ctxt->game->door_open_state[y][x] == '1' && !is_near)
	{
		ctxt->game->door_open_state[y][x] = '0';
	}
	return (!is_near);
}

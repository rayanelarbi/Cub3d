/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:00:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/02 10:16:05 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "utils/utils.h"
#include "config/constants.h"

/* Check if character is a valid floor tile */
static int	is_floor(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/* Check if a floor tile at (y, x) is surrounded by walls or floor */
static int	check_tile_surrounded(struct s_game *game, int y, int x)
{
	if (!is_floor(game->map[y][x]))
		return (SUCCESS);
	if (y == 0 || y == game->height - 1 || x == 0 || x == game->width - 1)
	{
		basic_error("Map not closed: floor at edge");
		return (ERROR);
	}
	if (game->map[y][x - 1] == ' ' || game->map[y][x + 1] == ' '
		|| game->map[y - 1][x] == ' ' || game->map[y + 1][x] == ' ')
	{
		basic_error("Map not closed: floor next to space");
		return (ERROR);
	}
	return (SUCCESS);
}

/* Validate that all floor tiles are properly enclosed by walls */
int	validate_map_closed(struct s_game *game)
{
	int	y;
	int	x;

	if (!game || !game->map)
		return (ERROR);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (check_tile_surrounded(game, y, x) == ERROR)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

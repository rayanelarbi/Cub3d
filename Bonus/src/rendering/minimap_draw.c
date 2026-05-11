/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/01/31 11:05:16 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "rendering/raycast.h"
#include "config/constants.h"

/* Calculate which map tile corresponds to screen position */
static void	calculate_tile_position(t_context *ctxt, int screen_x,
		int screen_y, int *tile_coords)
{
	int	viewport_size;
	int	cell_size;

	cell_size = MINIMAP_SIZE / (MINIMAP_SIZE / CELL_SIZE);
	viewport_size = MINIMAP_SIZE / cell_size;
	tile_coords[0] = (int)ctxt->player->pos.x - viewport_size / 2;
	tile_coords[1] = (int)ctxt->player->pos.y - viewport_size / 2;
	tile_coords[0] += (screen_x - OFFSET_X) / cell_size;
	tile_coords[1] += (screen_y - OFFSET_Y) / cell_size;
}

/* Fill a cell area with given color */
static void	fill_cell_area(t_context *ctxt, int screen_x, int screen_y,
		int color)
{
	int	px;
	int	py;

	py = 0;
	while (py < CELL_SIZE)
	{
		px = 0;
		while (px < CELL_SIZE)
		{
			my_mlx_pixel_put(ctxt->mlx, screen_x + px, screen_y + py, color);
			px++;
		}
		py++;
	}
}

/* Draw a square cell on minimap at given screen position with color */
void	draw_cell_at(t_context *ctxt, int screen_x, int screen_y)
{
	int	tile_coords[2];
	int	color;

	calculate_tile_position(ctxt, screen_x, screen_y, tile_coords);
	color = get_tile_color(ctxt, tile_coords[0], tile_coords[1]);
	fill_cell_area(ctxt, screen_x, screen_y, color);
}

/* Draw red dot at player position on minimap */
void	draw_player_center(t_context *ctxt, int center_x, int center_y)
{
	int	px;
	int	py;

	py = -3;
	while (py <= 3)
	{
		px = -3;
		while (px <= 3)
		{
			my_mlx_pixel_put(ctxt->mlx, center_x + px, center_y + py,
				PLAYER_COLOR);
			++px;
		}
		++py;
	}
}

/* Get color for minimap tile: black for walls, gray for floor */
int	get_tile_color(t_context *ctxt, int tile_x, int tile_y)
{
	char	tile;

	if (tile_x >= 0 && tile_x < ctxt->game->width
		&& tile_y >= 0 && tile_y < ctxt->game->height)
	{
		tile = ctxt->game->map[tile_y][tile_x];
		if (tile == '1' || tile == 'A')
			return (BLACK);
		if (tile == 'D')
		{
			if (ctxt->game->door_open_state
				&& ctxt->game->door_open_state[tile_y]
				&& ctxt->game->door_open_state[tile_y][tile_x] == '1')
				return (OPEN_DOOR_COLOR);
			return (DOOR_COLOR);
		}
		else
			return (SILVER);
	}
	return (CYPRUS);
}

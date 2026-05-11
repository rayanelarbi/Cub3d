/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/01/31 11:05:16 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "core/cub3d.h"
#include "rendering/raycast.h"
#include "config/constants.h"

/* Render minimap tiles in viewport centered on player */
static void	render_minimap_viewport(t_context *ctxt, int mm_size, int cell_s)
{
	int	params[7];

	params[0] = mm_size / cell_s;
	params[1] = (int)ctxt->player->pos.x - params[0] / 2;
	params[2] = (int)ctxt->player->pos.y - params[0] / 2;
	params[3] = 0;
	while (params[3] < params[0])
	{
		params[4] = 0;
		while (params[4] < params[0])
		{
			params[5] = OFFSET_X + params[4] * cell_s;
			params[6] = OFFSET_Y + params[3] * cell_s;
			draw_cell_at(ctxt, params[5], params[6]);
			params[4]++;
		}
		params[3]++;
	}
}

/* Draw horizontal borders (top and bottom) */
static void	draw_horizontal_borders(t_context *ctxt, int mm_size,
	int thickness)
{
	int	x;
	int	y;

	x = -thickness;
	while (x < mm_size + thickness)
	{
		y = -thickness;
		while (y < thickness)
		{
			my_mlx_pixel_put(ctxt->mlx, OFFSET_X + x,
				OFFSET_Y + y, BORDER_COLOR);
			my_mlx_pixel_put(ctxt->mlx, OFFSET_X + x,
				OFFSET_Y + mm_size - 1 - y, BORDER_COLOR);
			++y;
		}
		++x;
	}
}

/* Draw vertical borders (left and right) */
static void	draw_vertical_borders(t_context *ctxt, int mm_size, int thickness)
{
	int	x;
	int	y;

	y = -thickness;
	while (y < mm_size + thickness)
	{
		x = -thickness;
		while (x < thickness)
		{
			my_mlx_pixel_put(ctxt->mlx, OFFSET_X + x,
				OFFSET_Y + y, BORDER_COLOR);
			my_mlx_pixel_put(ctxt->mlx, OFFSET_X + mm_size - 1 - x,
				OFFSET_Y + y, BORDER_COLOR);
			++x;
		}
		++y;
	}
}

/* Draw white border around minimap with specified thickness */
static void	draw_minimap_border(t_context *ctxt, int mm_size)
{
	int	thickness;

	thickness = BORDER_THICKNESS;
	draw_horizontal_borders(ctxt, mm_size, thickness);
	draw_vertical_borders(ctxt, mm_size, thickness);
}

/* Draw complete minimap with viewport, border and player marker */
void	draw_minimap(t_context *ctxt)
{
	t_fov_params	params;

	if (!ctxt || !ctxt->game || !ctxt->game->map || !ctxt->player)
		return ;
	params.cell_s = CELL_SIZE;
	params.center_x = OFFSET_X + MINIMAP_SIZE / 2;
	params.center_y = OFFSET_Y + MINIMAP_SIZE / 2;
	render_minimap_viewport(ctxt, MINIMAP_SIZE, params.cell_s);
	draw_minimap_border(ctxt, MINIMAP_SIZE);
	draw_player_fov(ctxt, &params);
	draw_player_center(ctxt, params.center_x, params.center_y);
}

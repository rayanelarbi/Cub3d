/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:14:22 by boschwie          #+#    #+#             */
/*   Updated: 2026/01/31 11:05:16 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "core/cub3d.h"
#include "utils/utils.h"
#include "rendering/raycast.h"
#include "config/constants.h"

static double	trace_minimap_ray(t_context *ctxt, double vx, double vy,
		double max_world_range)
{
	const double	step = RAY_STEP;
	double			dist;
	double			sample_x;
	double			sample_y;

	dist = 0.0;
	while (dist < max_world_range)
	{
		sample_x = ctxt->player->pos.x + vx * dist;
		sample_y = ctxt->player->pos.y + vy * dist;
		if (sample_x < 0 || sample_y < 0
			|| sample_x >= ctxt->game->width || sample_y >= ctxt->game->height)
			break ;
		if (ctxt->game->map[(int)sample_y][(int)sample_x] == '1')
			break ;
		dist += step;
	}
	if (dist > max_world_range)
		dist = max_world_range;
	return (dist);
}

static void	draw_line(t_context *ctxt, t_draw_line_params *dlp)
{
	t_line_params	lp;
	int				e2;
	int				x;
	int				y;

	init_line_params(&lp, dlp);
	x = dlp->x0;
	y = dlp->y0;
	while (1)
	{
		my_mlx_pixel_put(ctxt->mlx, x, y, dlp->color);
		if (x == dlp->x1 && y == dlp->y1)
			break ;
		e2 = 2 * lp.err;
		if (e2 >= lp.dy)
		{
			lp.err += lp.dy;
			x += lp.step_x;
		}
		if (e2 <= lp.dx)
		{
			lp.err += lp.dx;
			y += lp.step_y;
		}
	}
}

static void	draw_fov_edge(t_context *ctxt, double edge[2], t_fov_params *p,
	int color)
{
	t_draw_line_params	dlp;
	double				range;

	normalize_edge(edge);
	range = trace_minimap_ray(ctxt, edge[0], edge[1], p->max_range);
	if (range <= 0.0)
		return ;
	dlp.x0 = p->center_x;
	dlp.y0 = p->center_y;
	dlp.x1 = p->center_x + (int)(edge[0] * range * p->cell_s);
	dlp.y1 = p->center_y + (int)(edge[1] * range * p->cell_s);
	dlp.color = color;
	draw_line(ctxt, &dlp);
}

void	draw_player_fov(t_context *ctxt, t_fov_params *params)
{
	t_player	*pl;
	double		left_edge[2];
	double		right_edge[2];

	if (!ctxt || !ctxt->player)
		return ;
	pl = ctxt->player;
	params->max_range = (double)(MINIMAP_SIZE / params->cell_s) / 2.0;
	left_edge[0] = pl->dir.x + pl->plane.x;
	left_edge[1] = pl->dir.y + pl->plane.y;
	right_edge[0] = pl->dir.x - pl->plane.x;
	right_edge[1] = pl->dir.y - pl->plane.y;
	draw_fov_edge(ctxt, left_edge, params, FOV_COLOR);
	draw_fov_edge(ctxt, right_edge, params, FOV_COLOR);
}

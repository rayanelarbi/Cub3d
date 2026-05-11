/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/01/31 10:57:40 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "rendering/raycast.h"

/* Calculate wall height and draw limits from perpendicular distance */
void	calc_wall_params(t_ray *ray, int *line_h,
		int *draw_limits, int screen_h)
{
	double	perp_dist;
	int		unclipped_start;
	int		unclipped_end;

	if (ray->side == 0)
		perp_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		perp_dist = ray->side_dist_y - ray->delta_dist_y;
	if (perp_dist < 0.001)
		perp_dist = 0.001;
	*line_h = (int)(screen_h / perp_dist);
	unclipped_start = -(*line_h) / 2 + screen_h / 2;
	unclipped_end = (*line_h) / 2 + screen_h / 2;
	draw_limits[0] = unclipped_start;
	draw_limits[1] = unclipped_end;
	draw_limits[2] = unclipped_start;
	if (draw_limits[0] < 0)
		draw_limits[0] = 0;
	if (draw_limits[1] >= screen_h)
		draw_limits[1] = screen_h - 1;
}

static void	init_draw_params(t_draw_params *p, int x,
	int *draw_limits, int line_height)
{
	p->x = x;
	p->draw_start = draw_limits[0];
	p->draw_end = draw_limits[1];
	p->line_height = line_height;
	p->unclipped_start = draw_limits[2];
}

/* Cast single ray for column x: init, DDA, calc params, draw */
void	cast_one_ray(t_context *ctxt, int x)
{
	t_ray			ray;
	t_draw_params	p;
	int				line_height;
	int				draw_limits[3];

	init_ray(&ray, ctxt->player, x, ctxt->mlx->screen_width);
	perform_dda(&ray, ctxt);
	calc_wall_params(&ray, &line_height, draw_limits,
		ctxt->mlx->screen_height);
	init_draw_params(&p, x, draw_limits, line_height);
	draw_vertical_line(ctxt, &ray, &p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/01 16:04:40 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "core/cub3d.h"
#include "rendering/raycast.h"
#include "game/game.h"

void	init_ray(t_ray *ray, t_player *pl, int x, int screen_w)
{
	ray->camera_x = 2.0 * x / (double)screen_w - 1.0;
	ray->ray_dir_x = pl->dir.x + pl->plane.x * ray->camera_x;
	ray->ray_dir_y = pl->dir.y + pl->plane.y * ray->camera_x;
	ray->map_x = (int)pl->pos.x;
	ray->map_y = (int)pl->pos.y;
	calculate_delta_distances(ray);
	setup_step_and_side_dist_x(ray, pl);
	setup_step_and_side_dist_y(ray, pl);
}

static int	check_hit_condition(t_context *ctxt, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_x < 0
		|| ray->map_y >= ctxt->game->height
		|| ray->map_x >= ctxt->game->width)
		return (1);
	if (ctxt->game->map[ray->map_y][ray->map_x] == '1')
		return (1);
	if (ctxt->game->map[ray->map_y][ray->map_x] == 'A')
		return (1);
	if (should_door_block(ctxt, ray->map_x, ray->map_y))
		return (1);
	return (0);
}

int	perform_dda(t_ray *ray, t_context *ctxt)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		perform_dda_step(ray);
		hit = check_hit_condition(ctxt, ray);
	}
	return (hit);
}

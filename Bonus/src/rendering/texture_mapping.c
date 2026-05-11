/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:14:05 by rlarbi            #+#    #+#             */
/*   Updated: 2026/01/31 11:05:16 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "rendering/raycast.h"
#include "rendering/texture.h"
#include <math.h>

/* Check if position is special texture (door or animation) */
static t_texture	*get_special_texture(t_context *ctxt, t_ray *ray)
{
	if (ray->map_y >= 0 && ray->map_y < ctxt->game->height && ray->map_x >= 0
		&& ray->map_x < ctxt->game->width
		&& ctxt->game->map[ray->map_y][ray->map_x] == 'D'
		&& ctxt->game->map_info.door_texture.addr)
		return (&ctxt->game->map_info.door_texture);
	if (ray->map_y >= 0 && ray->map_y < ctxt->game->height && ray->map_x >= 0
		&& ray->map_x < ctxt->game->width
		&& ctxt->game->map[ray->map_y][ray->map_x] == 'A'
		&& ctxt->game->map_info.anim_frames
		&& ctxt->game->map_info.anim_curr_frame
			< ctxt->game->map_info.anim_frame_count
		&& ctxt->game->map_info.anim_frames[
			ctxt->game->map_info.anim_curr_frame].addr)
		return (&ctxt->game->map_info.anim_frames[
				ctxt->game->map_info.anim_curr_frame]);
	return (NULL);
}

/* Select wall texture based on ray side and direction (NO/SO/WE/EA) */
static t_texture	*select_texture(t_context *ctxt, t_ray *ray)
{
	t_texture	*special;

	special = get_special_texture(ctxt, ray);
	if (special)
		return (special);
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&ctxt->game->map_info.textures[2]);
		return (&ctxt->game->map_info.textures[3]);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (&ctxt->game->map_info.textures[1]);
		return (&ctxt->game->map_info.textures[0]);
	}
}

/* Calculate exact wall hit position for texture mapping */
static double	calc_wall_x(t_ray *ray, t_player *pl)
{
	double	wall_x;
	double	perp_wall_dist;

	if (ray->side == 0)
	{
		perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
		wall_x = pl->pos.y + perp_wall_dist * ray->ray_dir_y;
	}
	else
	{
		perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
		wall_x = pl->pos.x + perp_wall_dist * ray->ray_dir_x;
	}
	wall_x = wall_x - floor(wall_x);
	return (wall_x);
}

/* Render one column of texture pixels */
static void	render_texture_column(t_context *ctxt, t_tex_render *tr,
	int x, t_draw_params *params)
{
	double	step;
	double	tex_pos;
	int		y;

	step = (double)tr->tex->height / (double)params->line_height;
	tex_pos = calc_initial_tex_pos(params, step);
	y = params->draw_start;
	while (y <= params->draw_end)
	{
		my_mlx_pixel_put(ctxt->mlx, x, y, get_texture_pixel(tr->tex, tr->tex_x,
				clamp_tex_y((int)tex_pos, tr->tex->height)));
		tex_pos += step;
		y++;
	}
}

/* Draw textured vertical wall column with correct texture mapping */
void	draw_textured_column(t_context *ctxt, t_ray *ray, int x,
		t_draw_params *params)
{
	t_tex_render	tr;
	double			wall_x;

	tr.tex = select_texture(ctxt, ray);
	wall_x = calc_wall_x(ray, ctxt->player);
	tr.tex_x = calc_texture_x(ray, wall_x, tr.tex->width);
	render_texture_column(ctxt, &tr, x, params);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_mapping_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:30:00 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 17:30:00 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "rendering/raycast.h"
#include <math.h>

/* Calculate horizontal texture coordinate (x-position on texture) */
int	calc_texture_x(t_ray *ray, double wall_x, int tex_width)
{
	int	tex_x;

	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		wall_x = 1.0 - wall_x;
	tex_x = (int)(wall_x * tex_width) % tex_width;
	return (tex_x);
}

/* Calculate initial texture Y position based on clipping */
double	calc_initial_tex_pos(t_draw_params *params, double step)
{
	int	pixels_skipped;

	pixels_skipped = params->draw_start - params->unclipped_start;
	return ((double)pixels_skipped * step);
}

/* Clamp texture Y coordinate to valid range */
int	clamp_tex_y(int tex_y, int tex_height)
{
	if (tex_y >= tex_height)
		return (tex_height - 1);
	if (tex_y < 0)
		return (0);
	return (tex_y);
}

/* Get pixel color from texture at coordinates (tex_x, tex_y) */
int	get_texture_pixel(t_texture *tex, int tex_x, int tex_y)
{
	char	*pixel;

	if (!tex || !tex->addr || tex_x < 0 || tex_x >= tex->width || tex_y < 0
		|| tex_y >= tex->height)
		return (MAGENTA);
	pixel = tex->addr + (tex_y * tex->line_length + tex_x * (tex->bits_per_pixel
				/ 8));
	return (*(int *)pixel);
}

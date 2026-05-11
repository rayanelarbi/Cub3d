/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/01/31 10:57:40 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "rendering/raycast.h"

/* Put pixel at (x,y) with color directly to image buffer */
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	int		bpp;

	if (!mlx || !mlx->addr)
		return ;
	if (x < 0 || x >= mlx->screen_width || y < 0 || y >= mlx->screen_height)
		return ;
	bpp = mlx->bits_per_pixel / 8;
	dst = mlx->addr + (y * mlx->line_length + x * bpp);
	*(unsigned int *)dst = (unsigned int)color;
}

/* Draw vertical line: ceiling, textured wall column, floor */
void	draw_vertical_line(t_context *ctxt, t_ray *ray, t_draw_params *p)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = ctxt->game->map_info.ceiling_color;
	floor_color = ctxt->game->map_info.floor_color;
	y = 0;
	while (y < p->draw_start)
	{
		my_mlx_pixel_put(ctxt->mlx, p->x, y, ceiling_color);
		y = y + 1;
	}
	draw_textured_column(ctxt, ray, p->x, p);
	y = p->draw_end + 1;
	while (y < ctxt->mlx->screen_height)
	{
		my_mlx_pixel_put(ctxt->mlx, p->x, y, floor_color);
		y = y + 1;
	}
}

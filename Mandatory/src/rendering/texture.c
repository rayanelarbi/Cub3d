/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:27:55 by boschwie          #+#    #+#             */
/*   Updated: 2025/10/07 18:27:55 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "config/constants.h"

/* Load XPM file into texture structure with image data */
int	load_xpm_into_texture(t_mlx *mlx, const char *path, t_texture *out)
{
	int	w;
	int	h;

	if (!mlx || !mlx->mlx || !path || !out)
		return (ERROR);
	out->img = mlx_xpm_file_to_image(mlx->mlx, (char *)path, &w, &h);
	if (!out->img)
		return (ERROR);
	out->addr = mlx_get_data_addr(out->img,
			&out->bits_per_pixel, &out->line_length, &out->endian);
	out->width = w;
	out->height = h;
	return (SUCCESS);
}

/* Destroy texture image and reset all fields to zero/NULL */
void	destroy_texture(t_mlx *mlx, t_texture *tex)
{
	if (!tex)
		return ;
	if (!mlx || !mlx->mlx)
		return ;
	if (tex->img && mlx && mlx->mlx)
	{
		mlx_destroy_image(mlx->mlx, tex->img);
		tex->img = NULL;
	}
	tex->addr = NULL;
	tex->width = 0;
	tex->height = 0;
	tex->bits_per_pixel = 0;
	tex->line_length = 0;
	tex->endian = 0;
}

/* Draw texture image to window at position (x, y) */
int	draw_texture(t_context *ctxt, t_texture *tex, int x, int y)
{
	if (!ctxt || !ctxt->mlx || !ctxt->mlx->mlx || !ctxt->mlx->mlx_win
		|| !tex || !tex->img)
		return (ERROR);
	mlx_put_image_to_window(ctxt->mlx->mlx, ctxt->mlx->mlx_win, tex->img, x, y);
	return (SUCCESS);
}

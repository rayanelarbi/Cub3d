/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:19:50 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/02 10:04:17 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "rendering/texture.h"
#include "utils/utils.h"
#include <unistd.h>
#include <string.h>

static int	init_mlx_image(t_context *ctxt, int screen_w, int screen_h)
{
	ctxt->mlx->img = mlx_new_image(ctxt->mlx->mlx, screen_w, screen_h);
	if (!ctxt->mlx->img)
		return (ERROR);
	ctxt->mlx->addr = mlx_get_data_addr(ctxt->mlx->img,
			&ctxt->mlx->bits_per_pixel, &ctxt->mlx->line_length,
			&ctxt->mlx->endian);
	if (!ctxt->mlx->addr)
		return (ERROR);
	ctxt->mlx->screen_width = screen_w;
	ctxt->mlx->screen_height = screen_h;
	ctxt->mlx->hotbar_item_img = mlx_xpm_file_to_image(ctxt->mlx->mlx,
			"assets/textures/diamond.xpm", &ctxt->mlx->hotbar_item_w,
			&ctxt->mlx->hotbar_item_h);
	if (ctxt->mlx->hotbar_item_img)
		ctxt->mlx->hotbar_item_addr = mlx_get_data_addr(
				ctxt->mlx->hotbar_item_img, &screen_w, &screen_h, &screen_w);
	return (SUCCESS);
}

/* Initialize MLX: connection, window, image and get screen dimensions */
int	initialize_mlx(char *filename, t_context *ctxt)
{
	int	screen_w;
	int	screen_h;

	ctxt->mlx->mlx = mlx_init();
	if (!ctxt->mlx->mlx)
		return (ERROR);
	mlx_get_screen_size(ctxt->mlx->mlx, &screen_w, &screen_h);
	ctxt->mlx->mlx_win = mlx_new_window(ctxt->mlx->mlx, screen_w, screen_h,
			filename);
	if (!ctxt->mlx->mlx_win)
		return (ERROR);
	if (init_mlx_image(ctxt, screen_w, screen_h) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

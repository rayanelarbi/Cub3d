/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:40:47 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/02 21:23:09 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "config/constants.h"
#include "rendering/raycast.h"

/* Render raycasted 3D view by casting rays for each screen column */
int	render_raycast(t_context *ctxt)
{
	int	x;

	if (!ctxt || !ctxt->player || !ctxt->mlx || !ctxt->mlx->addr)
		return (ERROR);
	x = 0;
	while (x < ctxt->mlx->screen_width)
	{
		cast_one_ray(ctxt, x);
		++x;
	}
	draw_minimap(ctxt);
	return (SUCCESS);
}

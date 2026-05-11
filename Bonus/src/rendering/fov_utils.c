/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:10:00 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 17:10:00 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "core/cub3d.h"
#include "utils/utils.h"
#include "rendering/raycast.h"
#include "config/constants.h"

void	normalize_edge(double edge[2])
{
	double	len;

	len = sqrt(edge[0] * edge[0] + edge[1] * edge[1]);
	if (len > 0.0)
	{
		edge[0] /= len;
		edge[1] /= len;
	}
}

int	step_direction(int from, int to)
{
	if (from < to)
		return (1);
	if (from > to)
		return (-1);
	return (0);
}

void	init_line_params(t_line_params *p, t_draw_line_params *dlp)
{
	p->dx = abs(dlp->x1 - dlp->x0);
	p->dy = -abs(dlp->y1 - dlp->y0);
	p->step_x = step_direction(dlp->x0, dlp->x1);
	p->step_y = step_direction(dlp->y0, dlp->y1);
	p->err = p->dx + p->dy;
}

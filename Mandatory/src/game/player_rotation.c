/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/02 10:02:24 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "core/cub3d.h"
#include "config/constants.h"

/* Rotate player direction and camera plane by given angle */
void	rotate_player(t_player *pl, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = pl->dir.x;
	pl->dir.x = pl->dir.x * cos(angle) - pl->dir.y * sin(angle);
	pl->dir.y = old_dir_x * sin(angle) + pl->dir.y * cos(angle);
	old_plane_x = pl->plane.x;
	pl->plane.x = pl->plane.x * cos(angle) - pl->plane.y * sin(angle);
	pl->plane.y = old_plane_x * sin(angle) + pl->plane.y * cos(angle);
}

/* Apply keyboard rotation based on turning flags */
void	apply_rotation(t_player *pl)
{
	if (pl->turning_left)
		rotate_player(pl, -pl->rot_speed);
	if (pl->turning_right)
		rotate_player(pl, pl->rot_speed);
}

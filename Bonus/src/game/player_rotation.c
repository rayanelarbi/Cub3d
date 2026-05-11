/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/02 21:00:53 by rlarbi           ###   ########.fr       */
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

/* Initialize mouse position at first call */
static int	init_mouse_position(t_context *ctxt, int center_x, int center_y)
{
	if (ctxt->player->mouse_x == -1)
	{
		ctxt->player->mouse_x = center_x;
		ctxt->player->mouse_y = center_y;
		mlx_mouse_move(ctxt->mlx->mlx_win, center_x, center_y);
		return (1);
	}
	return (0);
}

/* Handle mouse movement for camera rotation, recenter cursor */
int	mouse_motion_handler(int x, int y, t_context *ctxt)
{
	int		delta_x;
	double	rotation_angle;
	int		center_x;
	int		center_y;

	(void)y;
	if (!ctxt || !ctxt->player || ctxt->state != APP_PLAYING)
		return (SUCCESS);
	center_x = ctxt->mlx->screen_width / 2;
	center_y = ctxt->mlx->screen_height / 2;
	if (init_mouse_position(ctxt, center_x, center_y))
		return (SUCCESS);
	delta_x = x - center_x;
	if (delta_x != 0)
	{
		rotation_angle = delta_x * ctxt->player->mouse_sensitivity;
		rotate_player(ctxt->player, rotation_angle);
		mlx_mouse_move(ctxt->mlx->mlx_win, center_x, center_y);
	}
	ctxt->player->mouse_x = center_x;
	ctxt->player->mouse_y = center_y;
	return (SUCCESS);
}

/* Apply keyboard rotation based on turning flags */
void	apply_rotation(t_player *pl)
{
	if (pl->turning_left)
		rotate_player(pl, -pl->rot_speed);
	if (pl->turning_right)
		rotate_player(pl, pl->rot_speed);
}

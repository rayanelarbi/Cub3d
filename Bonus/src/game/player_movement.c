/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/01 15:57:41 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "game/game.h"

/* Check if a single check position is safe */
static int	is_check_pos_valid(t_context *ctxt, int check_x, int check_y)
{
	if (check_x < 0 || check_y < 0
		|| check_y >= ctxt->game->height
		|| check_x >= ctxt->game->width)
		return (0);
	if (ctxt->game->map[check_y][check_x] == '1'
		|| ctxt->game->map[check_y][check_x] == 'A')
		return (0);
	if (should_door_block(ctxt, check_x, check_y))
		return (0);
	return (1);
}

/* Check if position is safe with minimum wall distance */
static int	is_position_safe(t_context *ctxt, double x, double y)
{
	double	margin;
	int		check_x;
	int		check_y;
	int		i;
	int		j;

	margin = 0.3;
	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			check_x = (int)(x + i * margin);
			check_y = (int)(y + j * margin);
			if (!is_check_pos_valid(ctxt, check_x, check_y))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Try to move with sliding: check X and Y independently */
static void	try_move_with_slide(t_context *ctxt, t_player *pl,
		double new_x, double new_y)
{
	int	can_move_x;
	int	can_move_y;

	can_move_x = is_position_safe(ctxt, new_x, pl->pos.y);
	can_move_y = is_position_safe(ctxt, pl->pos.x, new_y);
	if (can_move_x && can_move_y)
	{
		pl->pos.x = new_x;
		pl->pos.y = new_y;
	}
	else if (can_move_x)
	{
		pl->pos.x = new_x;
	}
	else if (can_move_y)
	{
		pl->pos.y = new_y;
	}
}

/* Move player forward/backward if no wall collision */
void	move_forward_backward(t_context *ctxt, t_player *pl)
{
	double	new_x;
	double	new_y;

	if (pl->moving_forward)
	{
		new_x = pl->pos.x + pl->dir.x * pl->move_speed;
		new_y = pl->pos.y + pl->dir.y * pl->move_speed;
		try_move_with_slide(ctxt, pl, new_x, new_y);
	}
	if (pl->moving_backward)
	{
		new_x = pl->pos.x - pl->dir.x * pl->move_speed;
		new_y = pl->pos.y - pl->dir.y * pl->move_speed;
		try_move_with_slide(ctxt, pl, new_x, new_y);
	}
}

/* Strafe player left/right if no wall collision */
void	move_left_right(t_context *ctxt, t_player *pl)
{
	double	new_x;
	double	new_y;

	if (pl->moving_left)
	{
		new_x = pl->pos.x - pl->plane.x * pl->move_speed;
		new_y = pl->pos.y - pl->plane.y * pl->move_speed;
		try_move_with_slide(ctxt, pl, new_x, new_y);
	}
	if (pl->moving_right)
	{
		new_x = pl->pos.x + pl->plane.x * pl->move_speed;
		new_y = pl->pos.y + pl->plane.y * pl->move_speed;
		try_move_with_slide(ctxt, pl, new_x, new_y);
	}
}

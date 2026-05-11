/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/01/31 11:05:16 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "core/cub3d.h"
#include "config/constants.h"

/* Set player movement flags based on pressed key */
static int	handle_movement_keys(int key, t_player *player)
{
	if (key == UP || key == ARR_UP)
		player->moving_forward = 1;
	else if (key == DOWN || key == ARR_DOWN)
		player->moving_backward = 1;
	else if (key == LEFT)
		player->moving_left = 1;
	else if (key == RIGHT)
		player->moving_right = 1;
	else if (key == ARR_LEFT)
		player->turning_left = 1;
	else if (key == ARR_RIGHT)
		player->turning_right = 1;
	else if (key == KEY_E)
		player->action_key = 1;
	else
		return (-1);
	return (SUCCESS);
}

/* Main key press handler: route to system, menu or movement handlers */
int	key_handler(int key, t_context *ctxt)
{
	if (key == ESC || key == 65513)
	{
		free_structs(ctxt);
		exit(0);
	}
	if (key == KEY_P)
	{
		if (ctxt->state == APP_PLAYING)
		{
			ctxt->state = APP_PAUSED;
			mlx_mouse_show(ctxt->mlx->mlx, ctxt->mlx->mlx_win);
		}
		else
		{
			ctxt->state = APP_PLAYING;
			mlx_mouse_hide(ctxt->mlx->mlx, ctxt->mlx->mlx_win);
		}
		return (SUCCESS);
	}
	if (!ctxt->player || ctxt->state == APP_PAUSED)
		return (SUCCESS);
	handle_movement_keys(key, ctxt->player);
	return (SUCCESS);
}

/* Clear player movement flags when key is released */
int	key_release_handler(int key, t_context *ctxt)
{
	if (!ctxt || !ctxt->player)
		return (SUCCESS);
	if (key == UP || key == ARR_UP)
		ctxt->player->moving_forward = 0;
	else if (key == DOWN || key == ARR_DOWN)
		ctxt->player->moving_backward = 0;
	else if (key == LEFT)
		ctxt->player->moving_left = 0;
	else if (key == RIGHT)
		ctxt->player->moving_right = 0;
	else if (key == ARR_LEFT)
		ctxt->player->turning_left = 0;
	else if (key == ARR_RIGHT)
		ctxt->player->turning_right = 0;
	else if (key == KEY_E)
		ctxt->player->action_key = 0;
	return (SUCCESS);
}

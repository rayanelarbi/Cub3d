/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2025/12/07 17:45:06 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "game/game.h"

/* Apply player movement and rotation based on current input state */
static void	apply_movement(t_context *ctxt)
{
	t_player	*pl;

	if (!ctxt->player || !ctxt->game || !ctxt->game->map)
		return ;
	pl = ctxt->player;
	move_forward_backward(ctxt, pl);
	move_left_right(ctxt, pl);
	apply_rotation(pl);
}

/* Main application loop - render menu or game based on state */
int	game_loop(t_context *ctxt)
{
	if (ctxt->state == APP_PLAYING)
		apply_movement(ctxt);
	return (render_game(ctxt));
}

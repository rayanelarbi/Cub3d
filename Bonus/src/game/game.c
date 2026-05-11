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
	static int	frame_count = 0;
	const int	frames_per_step = FRAMES_PER_STEP;

	if (++frame_count % 2 != 0)
		return (SUCCESS);
	if (ctxt->state == APP_PLAYING)
	{
		apply_movement(ctxt);
		check_portal_sound(ctxt);
		check_teleport(ctxt);
		if (ctxt->player->action_key)
			toggle_door(ctxt);
	}
	if (ctxt->game && ctxt->game->map_info.anim_frame_count > 0)
	{
		ctxt->game->map_info.anim_curr_frame = (frame_count / frames_per_step)
			% ctxt->game->map_info.anim_frame_count;
	}
	return (render_game(ctxt));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:41:24 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 15:41:24 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <math.h>

# include "../core/types.h"
# include "../utils/utils.h"

/* Player initialization and management */
int			init_player_and_textures(t_context *ctxt);
void		set_direction_from_table(t_player *pl, int index);
void		init_player_direction(t_context *ctxt);
void		init_player_params(t_context *ctxt);

/* Game loop and updates */
int			game_loop(t_context *ctxt);
void		update_animations(t_context *ctxt);

/* Input handling */
int			key_handler(int key, t_context *ctxt);
int			key_release_handler(int key, t_context *ctxt);

/* Mouse handling */
int			mouse_motion_handler(int x, int y, t_context *ctxt);

/* Player movement */
void		move_forward_backward(t_context *ctxt, t_player *pl);
void		move_left_right(t_context *ctxt, t_player *pl);

/* Player rotation */
void		rotate_player(t_player *pl, double angle);
void		apply_rotation(t_player *pl);

#endif /* GAME_H */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/02 10:02:50 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "config/constants.h"
#include "utils/utils.h"
#include "game/game.h"

/* Load all game textures from map info */
static int	load_game_textures(t_context *ctxt)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (load_xpm_into_texture(ctxt->mlx,
				ctxt->game->map_info.textures[i].path,
				&ctxt->game->map_info.textures[i]) == ERROR)
		{
			basic_error("Failed to load texture");
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

/* Initialize player and load all textures */
int	init_player_and_textures(t_context *ctxt)
{
	if (load_game_textures(ctxt) == ERROR)
		return (ERROR);
	ctxt->player = c_alloc(1, sizeof(*(ctxt->player)));
	if (!ctxt->player)
	{
		basic_error("Memory allocation failed");
		return (ERROR);
	}
	init_player_params(ctxt);
	return (SUCCESS);
}

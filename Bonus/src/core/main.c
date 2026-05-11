/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:34:27 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 16:07:35 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "core/cub3d.h"
#include "core/types.h"
#include "utils/utils.h"
#include "config/constants.h"

#include "parsing/parser.h"
#include "game/game.h"

static int	allocate_context_structs(t_context **ctxt)
{
	*ctxt = c_alloc(1, sizeof(t_context));
	if (!*ctxt)
		return (ERROR);
	(*ctxt)->state = APP_PLAYING;
	(*ctxt)->mlx = c_alloc(1, sizeof(*((*ctxt)->mlx)));
	if (!(*ctxt)->mlx)
	{
		free(*ctxt);
		return (ERROR);
	}
	(*ctxt)->game = c_alloc(1, sizeof(*((*ctxt)->game)));
	if (!(*ctxt)->game)
	{
		free_structs(*ctxt);
		free(*ctxt);
		return (ERROR);
	}
	mem_set((*ctxt)->game, 0, sizeof(*((*ctxt)->game)));
	return (SUCCESS);
}

static int	setup_game(t_context *ctxt, char *map_file)
{
	if (validate_arguments(ctxt, map_file) == ERROR)
		return (ERROR);
	if (initialize_mlx("Cub3d", ctxt) == ERROR)
		return (ERROR);
	if (init_player_and_textures(ctxt) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static void	setup_hooks(t_context *ctxt)
{
	mlx_hook(ctxt->mlx->mlx_win, 2, 1, key_handler, ctxt);
	mlx_hook(ctxt->mlx->mlx_win, 3, 2, key_release_handler, ctxt);
	mlx_hook(ctxt->mlx->mlx_win, 6, 1L << 6, mouse_motion_handler, ctxt);
	mlx_hook(ctxt->mlx->mlx_win, 17, 0, free_structs, ctxt);
	mlx_loop_hook(ctxt->mlx->mlx, game_loop, ctxt);
	mlx_mouse_hide(ctxt->mlx->mlx, ctxt->mlx->mlx_win);
}

int	main(int ac, char **av)
{
	t_context	*ctxt;

	if (ac != 2)
	{
		basic_error("Usage: ./cub3d <map.cub>");
		return (ERROR);
	}
	if (allocate_context_structs(&ctxt) == ERROR)
		return (ERROR);
	if (setup_game(ctxt, av[1]) == ERROR)
	{
		cleanup_context(ctxt);
		return (ERROR);
	}
	ctxt->state = APP_PLAYING;
	setup_hooks(ctxt);
	mlx_loop(ctxt->mlx->mlx);
	free_structs(ctxt);
}

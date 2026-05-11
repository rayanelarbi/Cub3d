/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:53:28 by boschwie          #+#    #+#             */
/*   Updated: 2025/10/05 15:53:28 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "config/constants.h"
#include "utils/utils.h"
#include "core/cub3d.h"
#include "parsing/parser.h"

static void	cleanup_map_on_error(t_game *game, size_t current_row)
{
	size_t	r;

	r = 0;
	while (r < current_row)
	{
		free(game->map[r]);
		r++;
	}
	free(game->map);
	game->map = NULL;
}

static int	build_game_map(struct s_game *game, char **lines,
	size_t count, size_t maxw)
{
	char	**map;

	map = pad_lines_to_map(lines, count, maxw);
	if (!map)
	{
		basic_error("Memory allocation failed");
		return (ERROR);
	}
	game->map = map;
	game->height = (int)count;
	game->width = (int)maxw;
	return (SUCCESS);
}

static int	validate_game_map(struct s_game *game, size_t count)
{
	if (find_and_set_player(game) == ERROR
		|| validate_map_closed(game) == ERROR)
	{
		cleanup_map_on_error(game, count);
		return (ERROR);
	}
	return (SUCCESS);
}

int	get_map(char *filename, struct s_game *game)
{
	char	**lines;
	size_t	count;
	size_t	maxw;

	if (!filename || !game)
		return (ERROR);
	lines = collect_map_lines(filename, &count, &maxw);
	if (!lines || count == 0)
	{
		basic_error("Invalid map");
		strarray_delete_all(lines);
		return (ERROR);
	}
	if (build_game_map(game, lines, count, maxw) == ERROR)
	{
		strarray_delete_all(lines);
		return (ERROR);
	}
	strarray_delete_all(lines);
	return (validate_game_map(game, count));
}

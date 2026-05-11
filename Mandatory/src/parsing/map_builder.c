/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:53:28 by boschwie          #+#    #+#             */
/*   Updated: 2025/10/05 15:53:28 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "core/cub3d.h"
#include "utils/utils.h"
#include "config/constants.h"

/* Pads a single line with spaces to reach maximum width */
static char	*pad_single_line(const char *line, size_t maxw)
{
	size_t	k;
	size_t	len;
	char	*padded;

	k = 0;
	len = str_len((char *)line);
	padded = malloc(maxw + 1);
	if (!padded)
		return (NULL);
	while (k < maxw)
	{
		if (k < len)
			padded[k] = line[k];
		else
			padded[k] = ' ';
		k++;
	}
	padded[maxw] = '\0';
	return (padded);
}

/* Converts array of lines to rectangular map by padding each line */
char	**pad_lines_to_map(char **lines, size_t count, size_t maxw)
{
	size_t	r;
	char	**map;

	r = 0;
	map = malloc((count + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (r < count)
	{
		map[r] = pad_single_line(lines[r], maxw);
		if (!map[r])
		{
			while (r > 0)
			{
				r--;
				free(map[r]);
			}
			free(map);
			return (NULL);
		}
		r++;
	}
	map[count] = NULL;
	return (map);
}

/* Processes a map row to find player start position and direction */
static int	process_row(struct s_game *game, size_t r, int *player_count)
{
	size_t	c;
	char	ch;

	c = 0;
	while (c < (size_t)game->width)
	{
		ch = game->map[r][c];
		if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
		{
			(*player_count)++;
			game->starting_position.x = (float)c + 0.5f;
			game->starting_position.y = (float)r + 0.5f;
			game->starting_direction = ch;
			game->map[r][c] = '0';
		}
		c++;
	}
	return (SUCCESS);
}

/* Finds player start position in map and validates exactly one exists */
int	find_and_set_player(struct s_game *game)
{
	size_t	r;
	int		player_count;

	r = 0;
	player_count = 0;
	while (r < (size_t)game->height)
	{
		process_row(game, r, &player_count);
		r++;
	}
	if (player_count == 0)
		basic_error("No player start found");
	if (player_count > 1)
		basic_error("Multiple player starts found");
	if (player_count == 1)
		return (SUCCESS);
	return (ERROR);
}

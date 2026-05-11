/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/02 09:59:11 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "config/constants.h"
#include "core/cub3d.h"
#include "utils/utils.h"
#include "parsing/parser.h"

/* Sets floor (F) or ceiling (C) color from parsed config line */
int	set_color(struct s_map_info *map_info, char **parts, int *found_colors)
{
	int	tmp;

	if (str_cmp(parts[0], "F") == 0)
	{
		if (!parts[1] || parse_rgb_triplet(parts[1], &tmp) == ERROR)
			return (ERROR);
		map_info->floor_color = tmp;
		(*found_colors)++;
	}
	else if (str_cmp(parts[0], "C") == 0)
	{
		if (!parts[1] || parse_rgb_triplet(parts[1], &tmp) == ERROR)
			return (ERROR);
		map_info->ceiling_color = tmp;
		(*found_colors)++;
	}
	return (SUCCESS);
}

/* Returns array index (0-3) for texture key (NO,SO,WE,EA) */
int	texture_index(char *key)
{
	if (!key)
		return (-1);
	if (str_cmp(key, "NO") == 0)
		return (0);
	if (str_cmp(key, "SO") == 0)
		return (1);
	if (str_cmp(key, "WE") == 0)
		return (2);
	if (str_cmp(key, "EA") == 0)
		return (3);
	return (-1);
}

int	set_texture(struct s_map_info *map_info, char **parts, int *found)
{
	int	idx;

	idx = texture_index(parts[0]);
	if (idx >= 0)
		return (assign_texture(map_info, idx, parts[1], found));
	return (SUCCESS);
}

/* Processes single config line to extract texture or color data */
int	process_config_line(char *line, struct s_map_info *map_info,
		int *found_textures, int *found_colors)
{
	char	*trimmed;
	char	**parts;
	int		rc;

	trimmed = str_trim(line, "\n\r\t ");
	if (!trimmed)
		return (SUCCESS);
	if (trimmed[0] == '\0')
	{
		free(trimmed);
		return (SUCCESS);
	}
	parts = split(trimmed, ' ');
	free(trimmed);
	if (!parts)
		return (SUCCESS);
	rc = set_texture(map_info, parts, found_textures);
	if (rc == SUCCESS)
		rc = set_color(map_info, parts, found_colors);
	strarray_delete_all(parts);
	return (rc);
}

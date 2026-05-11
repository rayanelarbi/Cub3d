/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:00:00 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 17:00:00 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "config/constants.h"
#include "core/cub3d.h"
#include "utils/utils.h"
#include "parsing/parser.h"

int	assign_texture(struct s_map_info *map_info, int idx, char *path,
		int *found)
{
	if (!path || str_len(path) == 0)
	{
		basic_error("Missing texture path");
		return (ERROR);
	}
	if (map_info->textures[idx].path)
		free(map_info->textures[idx].path);
	map_info->textures[idx].path = str_dup(path);
	(*found)++;
	return (SUCCESS);
}

int	assign_door_texture(struct s_map_info *map_info, char *path)
{
	if (!path || str_len(path) == 0)
	{
		basic_error("Missing door texture path");
		return (ERROR);
	}
	if (map_info->door_texture.path)
		free(map_info->door_texture.path);
	map_info->door_texture.path = str_dup(path);
	return (SUCCESS);
}

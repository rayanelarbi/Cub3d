/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config_validation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/01/31 11:05:16 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "config/constants.h"
#include "core/cub3d.h"
#include "utils/utils.h"

/* Validates that all required textures and colors are defined */
int	validate_config(struct s_map_info *map_info, int found_textures,
		int found_colors, char *filename)
{
	if (found_textures < 4)
	{
		basic_error("Not all textures defined (NO, SO, WE, EA required)");
		free_map_info(map_info);
		return (ERROR);
	}
	if (found_colors < 2)
	{
		basic_error("Floor and ceiling colors (F, C) missing");
		free_map_info(map_info);
		return (ERROR);
	}
	if (map_info->filename)
		free(map_info->filename);
	map_info->filename = str_dup(filename);
	return (SUCCESS);
}

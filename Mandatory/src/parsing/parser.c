/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:22:32 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/01 15:58:34 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "config/constants.h"
#include "core/cub3d.h"
#include "utils/utils.h"
#include "parsing/parser.h"

/* Opens file and returns file descriptor, or error on failure */
static int	open_file(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		basic_error("Open failed");
	return (fd);
}

/* Processes config file line by line to extract textures and colors */
static int	process_file(int fd, struct s_map_info *map_info,
		int *found_textures, int *found_colors)
{
	char	*line;
	int		rc;

	*found_textures = 0;
	*found_colors = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		rc = process_config_line(line, map_info,
				found_textures, found_colors);
		free(line);
		if (rc == ERROR)
			return (ERROR);
		if (*found_textures >= 4 && *found_colors >= 2)
			return (SUCCESS);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}

int	get_textures(char *filename, struct s_map_info *map_info)
{
	int	fd;
	int	found_textures;
	int	found_colors;

	if (!filename || !map_info)
		return (ERROR);
	fd = open_file(filename);
	if (fd < 0)
	{
		free_map_info(map_info);
		return (ERROR);
	}
	if (process_file(fd, map_info, &found_textures, &found_colors) == ERROR)
	{
		get_next_line(-1);
		close(fd);
		free_map_info(map_info);
		return (ERROR);
	}
	get_next_line(-1);
	close(fd);
	return (validate_config(map_info, found_textures, found_colors, filename));
}

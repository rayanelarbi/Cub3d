/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:24:28 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 16:03:21 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "core/cub3d.h"
#include "utils/utils.h"
#include "config/constants.h"
#include "parsing/parser.h"

static int	validate_file_accessible(char *filename)
{
	int		fd;
	char	buf;
	int		n;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		basic_error("Open failed");
		return (ERROR);
	}
	n = read(fd, &buf, 1);
	if (n == -1 || n == 0)
	{
		basic_error("Read failed");
		close(fd);
		return (ERROR);
	}
	close(fd);
	return (SUCCESS);
}

int	check_extension(char *filename)
{
	size_t	len;

	if (!filename)
	{
		basic_error("No file provided");
		return (ERROR);
	}
	len = str_len(filename);
	if (len < 4)
	{
		basic_error("Wrong file extension");
		return (ERROR);
	}
	if (filename[len - 1] != 'b' || filename[len - 2] != 'u'
		|| filename[len - 3] != 'c' || filename[len - 4] != '.')
	{
		basic_error("Wrong file extension");
		return (ERROR);
	}
	return (validate_file_accessible(filename));
}

/* Validates arguments and loads textures and map from file */
int	validate_arguments(t_context *ctxt, char *filename)
{
	if (!filename)
		return (ERROR);
	if (check_extension(filename))
		return (ERROR);
	if (get_textures(filename, &ctxt->game->map_info))
		return (ERROR);
	if (get_map(filename, ctxt->game))
		return (ERROR);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
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

static int	process_map_line(t_map_collect *mc)
{
	t_list	*node;

	mc->in_map = 1;
	node = lst_new(str_dup(mc->line));
	if (!node || !node->content)
	{
		if (node)
			free(node);
		return (ERROR);
	}
	lst_add_back(&mc->head, node);
	if (str_len(node->content) > mc->maxw)
		mc->maxw = str_len(node->content);
	return (SUCCESS);
}

static int	init_collect(t_map_collect *mc, const char *filename)
{
	mc->fd = open(filename, O_RDONLY);
	mc->head = NULL;
	mc->maxw = 0;
	mc->in_map = 0;
	mc->line = NULL;
	if (mc->fd < 0)
	{
		basic_error("open failed");
		return (ERROR);
	}
	return (SUCCESS);
}

static int	handle_map_line(t_map_collect *mc)
{
	strip_eol(mc->line);
	if (is_map_line(mc->line))
	{
		if (process_map_line(mc) == ERROR)
			return (ERROR);
	}
	else if (mc->in_map && mc->line[0] != '\n' && mc->line[0] != '\0')
		return (ERROR);
	return (SUCCESS);
}

static char	**finalize_collection(t_map_collect *mc, size_t *out_count,
	size_t *out_maxw)
{
	char	**arr;

	if (!mc->head)
		return (NULL);
	arr = list_to_array(mc->head, out_count);
	clear_nodes_keep_content(&mc->head);
	*out_maxw = mc->maxw;
	return (arr);
}

char	**collect_map_lines(const char *filename, size_t *out_count,
			size_t *out_maxw)
{
	t_map_collect	mc;
	char			**arr;

	*out_count = 0;
	*out_maxw = 0;
	if (init_collect(&mc, filename) == ERROR)
		return (NULL);
	mc.line = get_next_line(mc.fd);
	while (mc.line != NULL)
	{
		if (handle_map_line(&mc) == ERROR)
		{
			cleanup_collect(&mc, NULL);
			return (NULL);
		}
		free(mc.line);
		mc.line = get_next_line(mc.fd);
	}
	close(mc.fd);
	arr = finalize_collection(&mc, out_count, out_maxw);
	return (arr);
}

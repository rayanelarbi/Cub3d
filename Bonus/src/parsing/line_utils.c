/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:04:30 by boschwie          #+#    #+#             */
/*   Updated: 2025/10/07 10:04:30 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "config/constants.h"
#include "core/cub3d.h"

static int	reallocate_buffer(char **buf, size_t *cap)
{
	char	*new;
	size_t	new_cap;
	size_t	i;

	if (*cap == 0)
		new_cap = 128;
	else
		new_cap = (*cap * 2);
	new = malloc(new_cap);
	if (!new)
		return (ERROR);
	i = 0;
	while (i < *cap && *buf)
	{
		new[i] = (*buf)[i];
		i++;
	}
	if (*buf)
		free(*buf);
	*buf = new;
	*cap = new_cap;
	return (SUCCESS);
}

int	append_char(char **buf, size_t *len, size_t *cap, char c)
{
	if (*len + 1 >= *cap)
	{
		if (reallocate_buffer(buf, cap) == ERROR)
			return (ERROR);
	}
	(*buf)[(*len)++] = c;
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/10/05 15:53:28 by boschwie          #+#    #+#             */
/*   Updated: 2025/10/05 15:53:28 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/constants.h"
#include "core/cub3d.h"
#include "utils/utils.h"
#include <stdlib.h>

/* Checks if line contains valid map characters (0,1,N,S,E,W,spaces) */
int	is_map_line(const char *s)
{
	size_t	i;
	char	c;
	int		has_map;

	i = 0;
	c = 0;
	has_map = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		c = s[i];
		if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
			|| c == 'D' || c == 'A')
			has_map = 1;
		else if (is_whitespace(c))
			;
		else
			return (0);
		i++;
	}
	return (has_map);
}

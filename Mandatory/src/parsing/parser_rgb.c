/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rgb.c                                       :+:      :+:    :+:   */
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

/* Validates that RGB components are non-empty and contain only digits */
static int	is_component_empty(char *p)
{
	if (!p || p[0] == '\0')
	{
		basic_error("RGB: Empty component");
		return (ERROR);
	}
	return (SUCCESS);
}

/* Validates that RGB components are non-empty and contain only digits */
static int	validate_rgb_parts(char **parts)
{
	int		i;
	char	*p;
	size_t	k;

	i = 0;
	while (i < 3)
	{
		p = parts[i];
		k = 0;
		if (is_component_empty(parts[i]) == ERROR)
			return (ERROR);
		while (p[k])
		{
			if (!is_digit((int)p[k]))
			{
				basic_error("RGB: Non digit");
				return (ERROR);
			}
			k++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	parse_single_component(const char *str, int *value)
{
	int	val;
	int	i;

	val = 0;
	i = 0;
	while (str[i] && is_digit(str[i]))
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	if (val < 0 || val > 255)
		return (ERROR);
	*value = val;
	return (SUCCESS);
}

static int	extract_rgb_values(char **parts, int *r, int *g, int *b)
{
	if (parse_single_component(parts[0], r) == ERROR)
		return (ERROR);
	if (parse_single_component(parts[1], g) == ERROR)
		return (ERROR);
	if (parse_single_component(parts[2], b) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	parse_rgb_triplet(const char *s, int *out_color)
{
	char	**parts;
	int		rgb[3];
	int		result;

	if (!s || !out_color)
		return (ERROR);
	parts = split(s, ',');
	if (!parts || strarray_size(parts) != 3)
	{
		strarray_delete_all(parts);
		basic_error("RGB must have exactly 3 components");
		return (ERROR);
	}
	if (validate_rgb_parts(parts) == ERROR)
	{
		strarray_delete_all(parts);
		basic_error("RGB values are invalid");
		return (ERROR);
	}
	result = extract_rgb_values(parts, &rgb[0], &rgb[1], &rgb[2]);
	strarray_delete_all(parts);
	if (result == ERROR)
		return (basic_error("RGB extraction failed"), ERROR);
	*out_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (SUCCESS);
}

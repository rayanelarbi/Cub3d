/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:18:26 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 15:36:07 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "core/cub3d.h"
#include "config/constants.h"
#include "utils/utils.h"

/* Compares 2 strings, returning any difference if found,
 * or an error in case at least on of the strings doesn't exist
*/
int	str_cmp(char *s1, char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

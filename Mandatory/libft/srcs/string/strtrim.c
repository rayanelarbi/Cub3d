/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:14:03 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:20:05 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static size_t	char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*str_trim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new;

	start = 0;
	while (s1[start] && char_in_set(s1[start], set))
		start++;
	end = str_len(s1);
	while (end > start && char_in_set(s1[end -1], set))
		end --;
	new = malloc(sizeof(char) * (end - start + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}

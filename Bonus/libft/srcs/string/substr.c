/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:28:57 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:20:05 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*sub_str(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	size;
	char			*new;

	size = str_len(s);
	if (start + len > size)
		len = size - start;
	if (size < start)
	{
		new = malloc(sizeof(char) * 1);
		if (new == NULL)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	i = 0;
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (i < len && s[start])
		new[i++] = (s[start++]);
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:12:59 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:20:05 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	str_lcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ld;

	i = 0;
	ld = str_len(dst);
	if (size <= ld)
		return (str_len(src) + size);
	while (src[i] && (ld + i) < size - 1)
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = '\0';
	return (ld + str_len(src));
}

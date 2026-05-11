/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:48:00 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:16:09 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

int	mem_cmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*comp;
	unsigned char	*with;

	comp = (unsigned char *)s1;
	with = (unsigned char *)s2;
	while (n--)
	{
		if (*comp != *with)
			return (*comp - *with);
		comp++;
		with++;
	}
	return (0);
}

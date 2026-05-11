/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:21:07 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:13:51 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static size_t	nb_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*i_to_a(int n)
{
	int		len;
	char	*num;
	long	nb;

	len = nb_len(n);
	nb = n;
	num = malloc(sizeof(char) * len + 1);
	if (!num)
		return (NULL);
	if (nb < 0)
	{
		num[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		num[0] = '0';
	num[len--] = '\0';
	while (nb)
	{
		num[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (num);
}

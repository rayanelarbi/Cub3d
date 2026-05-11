/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:48:18 by bschwiet          #+#    #+#             */
/*   Updated: 2025/10/05 11:15:27 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	a_to_i(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = (-1);
		nptr++;
	}
	while (is_digit((int)*nptr))
	{
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	return (res * sign);
}

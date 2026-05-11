/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:21:39 by boschwie          #+#    #+#             */
/*   Updated: 2024/12/20 10:38:56 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	count_pointer(unsigned long long prt)
{
	int	count;

	count = 0;
	while (prt != 0)
	{
		count++;
		prt = prt / 16;
	}
	return (count);
}

int	print_pointer(unsigned long long prt)
{
	if (prt >= 16)
	{
		print_pointer(prt / 16);
		print_pointer(prt % 16);
	}
	else
	{
		if (prt <= 9)
			put_char(prt + 48);
		else
			put_char(prt - 10 + 'a');
	}
	return (count_pointer(prt));
}

int	put_pointer(unsigned long long ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len += write (1, "(nil)", 5);
		return (len);
	}
	len = write (1, "0x", 2);
	len += print_pointer(ptr);
	return (len);
}

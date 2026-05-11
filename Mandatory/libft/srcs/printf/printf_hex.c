/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:21:18 by boschwie          #+#    #+#             */
/*   Updated: 2024/12/20 10:38:45 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	hex_len(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		num = num / 16;
		length++;
	}
	return (length);
}

void	print_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		print_hex(num / 16, format);
		print_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			put_char((num + '0'));
		else
		{
			if (format == 'x')
				put_char((num - 10 + 'a'));
			if (format == 'X')
				put_char((num - 10 + 'A'));
		}
	}
}

int	put_hexadecimal(unsigned int num, const char type)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		print_hex(num, type);
	return (hex_len(num));
}

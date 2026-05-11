/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:22:04 by boschwie          #+#    #+#             */
/*   Updated: 2024/12/20 10:39:01 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *str)
{
	int		len;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	len = str_len(str);
	write (1, str, len);
	return (len);
}

int	put_numb(int n)
{
	int		len;
	char	*str;

	str = i_to_a(n);
	len = put_str(str);
	free(str);
	return (len);
}

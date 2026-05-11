/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:36:12 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:14:20 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

void	put_nbr_fd(int n, int fd)
{
	if (n == -2147483648)
		put_str_fd("-2147483648", fd);
	else if (n < 0)
	{
		put_char_fd('-', fd);
		put_nbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		put_nbr_fd(n / 10, fd);
		put_char_fd(n % 10 + '0', fd);
	}
	else if (n >= 0 && n <= 9)
		put_char_fd(n + '0', fd);
}

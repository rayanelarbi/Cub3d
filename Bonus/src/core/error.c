/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:17:02 by boschwie          #+#    #+#             */
/*   Updated: 2026/01/31 10:57:25 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "utils/utils.h"

/* Write error prefix in red color to stderr */
static void	prefix(void)
{
	write(2, "\033[1m\033[31mError : \033[0m", 21);
}

/* Display error message with red prefix to stderr */
void	basic_error(char *msg)
{
	prefix();
	write (2, msg, str_len(msg));
	write (2, "\n", 1);
}

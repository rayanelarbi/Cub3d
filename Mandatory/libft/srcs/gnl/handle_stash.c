/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:33:24 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 16:33:24 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*handle_stash(char **stash)
{
	int	i;

	i = 0;
	while (i < 1025)
	{
		if (stash[i])
			free_ptr(&stash[i]);
		i++;
	}
	return (NULL);
}

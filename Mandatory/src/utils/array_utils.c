/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:58:10 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 15:35:57 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/* Function that returns the number of strings in a string array */
size_t	strarray_size(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/* Free all strings in array and the array pointer itself */
void	strarray_delete_all(char **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

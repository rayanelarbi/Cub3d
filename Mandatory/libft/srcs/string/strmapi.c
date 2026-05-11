/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:45:24 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:20:05 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*str_mapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*string;

	if (!s || !f)
		return (NULL);
	i = 0;
	string = malloc(sizeof(char) * (str_len(s)) + 1);
	if (string == NULL)
		return (NULL);
	while (s[i])
	{
		string[i] = f(i, (char)s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}

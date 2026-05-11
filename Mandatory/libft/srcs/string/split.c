/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:44:28 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:20:06 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static char	*str_ndup(const char *s, size_t n)
{
	size_t	i;
	char	*new;

	i = 0;
	new = NULL;
	if (n == 0)
		return (NULL);
	new = malloc(sizeof(char) * (n + 1));
	if (new == 0)
		return (NULL);
	while (i < n)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**free_all(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			count++;
		i++;
	}
	return (count);
}

char	**split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	k;
	size_t	save;

	i = 0;
	k = 0;
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (i < count_words(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		save = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		tab[i] = str_ndup(&s[save], k - save);
		if (tab[i++] == 0)
			return (free_all(tab));
	}
	tab[i] = NULL;
	return (tab);
}

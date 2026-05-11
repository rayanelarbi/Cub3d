/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:12:21 by boschwie          #+#    #+#             */
/*   Updated: 2024/11/16 19:12:21 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *str, int c)
{
	size_t	i;
	size_t	len;

	if (!str)
		return (NULL);
	i = 0;
	len = gnl_strlen(str);
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*gnl_strdup(char *src)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	len = gnl_strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	dup[len] = '\0';
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = gnl_strlen(s1) + gnl_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start >= gnl_strlen(s))
		return (gnl_strdup(""));
	if (len >= gnl_strlen(&s[start]))
		sub = malloc(sizeof(char) * (gnl_strlen(&s[start]) + 1));
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

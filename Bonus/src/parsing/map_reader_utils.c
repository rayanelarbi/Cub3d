/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:45:00 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 16:45:00 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "config/constants.h"
#include "utils/utils.h"
#include "core/cub3d.h"
#include "parsing/parser.h"

/* Removes trailing newline and carriage return characters from string */
void	strip_eol(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = str_len(s);
	while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
	{
		s[len - 1] = '\0';
		len--;
	}
}

/* Frees linked list nodes but keeps the content pointers intact */
void	clear_nodes_keep_content(t_list **head)
{
	t_list	*cur;
	t_list	*next;

	if (!head || !*head)
		return ;
	cur = *head;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*head = NULL;
}

/* Converts linked list of strings to null-terminated array */
char	**list_to_array(t_list *head, size_t *out_count)
{
	size_t	n;
	size_t	i;
	char	**arr;
	t_list	*cur;

	n = lst_size(head);
	arr = malloc(sizeof(char *) * (n + 1));
	if (!arr)
		return (NULL);
	i = 0;
	cur = head;
	while (cur)
	{
		arr[i++] = (char *)cur->content;
		cur = cur->next;
	}
	arr[i] = NULL;
	*out_count = n;
	return (arr);
}

void	cleanup_collect(t_map_collect *mc, char **arr)
{
	t_list	*next;

	while (mc->head)
	{
		next = mc->head->next;
		free(mc->head->content);
		free(mc->head);
		mc->head = next;
	}
	if (arr)
		strarray_delete_all(arr);
	if (mc->line)
		free(mc->line);
	close(mc->fd);
}

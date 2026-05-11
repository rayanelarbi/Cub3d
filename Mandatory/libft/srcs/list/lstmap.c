/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:15:04 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:15:35 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*lst_map(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = lst_new(set);
		if (!new_node)
		{
			del(set);
			lst_clear(&new_lst, (*del));
			return (new_lst);
		}
		lst_add_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

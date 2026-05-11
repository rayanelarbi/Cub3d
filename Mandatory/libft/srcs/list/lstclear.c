/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:12:55 by bschwiet          #+#    #+#             */
/*   Updated: 2025/09/24 17:15:26 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	lst_clear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (!*lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		lst_del_one(*lst, del);
		*lst = ptr;
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:12:03 by boschwie          #+#    #+#             */
/*   Updated: 2025/09/24 17:12:11 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

/* Linked list structure */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Linked list functions */
t_list	*lst_new(void *content);
void	lst_add_front(t_list **lst, t_list *new);
int		lst_size(t_list *lst);
t_list	*lst_last(t_list *lst);
void	lst_add_back(t_list **lst, t_list *new);
void	lst_del_one(t_list *lst, void (*del)(void*));
void	lst_clear(t_list **lst, void (*del)(void*));
void	lst_iter(t_list *lst, void (*f)(void*));
t_list	*lst_map(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif

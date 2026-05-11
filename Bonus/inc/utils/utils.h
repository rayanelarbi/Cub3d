/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:03:25 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 15:37:31 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

# include "../libft/includes/libft.h"

/* Basic error function */
void		basic_error(char *msg);

/* Character related helpers */
int			is_whitespace(char c);
int			abs(int x);

/* String related functions */
int			str_cmp(char *s1, char *s2);

/* String array related functions */
size_t		strarray_size(char **array);
void		strarray_delete_all(char **array);

#endif /* UTILS_H */

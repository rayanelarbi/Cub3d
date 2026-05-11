/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:13:11 by boschwie          #+#    #+#             */
/*   Updated: 2024/11/16 19:13:11 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*handle_stash(char **stash);

/*						UTILS							*/

size_t	gnl_strlen(char *str);
void	free_ptr(char **ptr);
char	*gnl_strchr(char *str, int c);
char	*gnl_strdup(char *src);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char *s, unsigned int start, size_t len);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:11:48 by boschwie          #+#    #+#             */
/*   Updated: 2025/10/05 11:11:35 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <unistd.h>

/* File descriptor output functions */
void	put_char_fd(char c, int fd);
void	put_str_fd(char *s, int fd);
void	put_endl_fd(char *s, int fd);
void	put_nbr_fd(int n, int fd);

#endif

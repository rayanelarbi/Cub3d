/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:09:24 by bschwiet          #+#    #+#             */
/*   Updated: 2024/12/20 10:49:48 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# include "libft.h"

int		print_f(const char *format, ...);
int		put_char(char c);
int		put_str(char *str);
int		put_numb(int n);
int		put_pointer(unsigned long long ptr);
int		put_unsigned(unsigned int n);
int		put_hexadecimal(unsigned int num, const char type);

#endif

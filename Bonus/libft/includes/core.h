/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:10:52 by boschwie          #+#    #+#             */
/*   Updated: 2025/10/05 11:10:48 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <stdlib.h>

/* Character classification functions */
int		is_alpha(int c);
int		is_digit(int c);
int		is_alnum(int c);
int		is_ascii(int c);
int		is_print(int c);

/* Character conversion functions */
int		to_upper(int c);
int		to_lower(int c);

/* Conversion functions */
int		a_to_i(const char *nptr);
char	*i_to_a(int n);

#endif

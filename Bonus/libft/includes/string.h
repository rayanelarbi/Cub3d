/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:11:16 by boschwie          #+#    #+#             */
/*   Updated: 2025/09/24 17:11:22 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stdlib.h>

/* String length and search functions */
size_t	str_len(const char *s);
char	*str_chr(const char *s, int c);
char	*str_rchr(const char *s, int c);
char	*str_nstr(const char *big, const char *little, size_t len);

/* String comparison functions */
int		str_ncmp(const char *s1, const char *s2, size_t n);

/* String copy and concatenation functions */
size_t	str_lcpy(char *dst, const char *src, size_t size);
size_t	str_lcat(char *dst, const char *src, size_t size);
char	*str_dup(const char *s);

/* String manipulation functions */
char	*sub_str(char const *s, unsigned int start, size_t len);
char	*str_join(char const *s1, char const *s2);
char	*str_trim(char const *s1, char const *set);
char	**split(char const *s, char c);

/* String transformation functions */
char	*str_mapi(char const *s, char (*f)(unsigned int, char));
void	str_iteri(char *s, void (*f)(unsigned int, char*));

#endif

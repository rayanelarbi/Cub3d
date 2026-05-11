/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:11:32 by boschwie          #+#    #+#             */
/*   Updated: 2025/09/24 17:11:38 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdlib.h>

/* Memory manipulation functions */
void	*mem_set(void *s, int c, size_t n);
void	b_zero(void *s, size_t n);
void	*mem_cpy(void *dest, const void *src, size_t n);
void	*mem_move(void *dest, const void *src, size_t n);

/* Memory search and comparison functions */
void	*mem_chr(const void *s, int c, size_t n);
int		mem_cmp(const void *s1, const void *s2, size_t n);

/* Memory allocation functions */
void	*c_alloc(size_t nmemb, size_t size);

#endif

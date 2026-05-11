/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:57:50 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 15:36:03 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Check if character is a whitespace (space, tab, newline, CR) */
int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int	abs(int x)
{
	return ((x > 0) * x + (x < 0) * -x);
}

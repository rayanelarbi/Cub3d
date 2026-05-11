/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:59:44 by boschwie          #+#    #+#             */
/*   Updated: 2025/10/07 15:59:44 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "config/constants.h"

void	render_hotbar(t_context *ctxt);

/* Main game render function: clear window and draw raycast view */
int	render_game(t_context *ctxt)
{
	mlx_clear_window(ctxt->mlx->mlx, ctxt->mlx->mlx_win);
	render_raycast(ctxt);
	render_hotbar(ctxt);
	return (SUCCESS);
}

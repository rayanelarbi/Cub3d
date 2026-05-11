/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotbar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:00:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/01 19:51:32 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/cub3d.h"
#include "config/constants.h"

static void	put_pixel(t_context *ctxt, int x, int y, int color)
{
	if (x >= 0 && x < ctxt->mlx->screen_width
		&& y >= 0 && y < ctxt->mlx->screen_height)
		((int *)ctxt->mlx->addr)[y * ctxt->mlx->screen_width + x] = color;
}

static void	fill_rect(t_context *c, int *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p[3])
	{
		j = 0;
		while (j < p[2])
		{
			put_pixel(c, p[0] + j, p[1] + i, p[4]);
			j++;
		}
		i++;
	}
}

static void	draw_slot(t_context *c, int x, int y, int sel)
{
	int	p[5];

	if (sel)
	{
		p[0] = x - 1;
		p[1] = y - 1;
		p[2] = 52;
		p[3] = 52;
		p[4] = 0xFFFFFF;
		fill_rect(c, p);
	}
	p[0] = x;
	p[1] = y;
	p[2] = 50;
	p[3] = 50;
	p[4] = 0x373737;
	fill_rect(c, p);
	p[0] = x + 1;
	p[1] = y + 1;
	p[2] = 48;
	p[3] = 48;
	p[4] = 0x8B8B8B;
	fill_rect(c, p);
}

static void	draw_item_icon(t_context *c, int x, int y)
{
	int		d[2];
	int		s[2];
	int		color;
	float	scale_x;
	float	scale_y;

	if (!c->mlx->hotbar_item_img || !c->mlx->hotbar_item_addr)
		return ;
	scale_x = (float)c->mlx->hotbar_item_w / 52.0f;
	scale_y = (float)c->mlx->hotbar_item_h / 52.0f;
	d[1] = -1;
	while (++d[1] < 52)
	{
		d[0] = -1;
		while (++d[0] < 52)
		{
			s[0] = (int)(d[0] * scale_x);
			s[1] = (int)(d[1] * scale_y);
			color = ((int *)c->mlx->hotbar_item_addr)[s[1]
				* c->mlx->hotbar_item_w + s[0]];
			if ((color & 0xFF000000) != 0xFF000000)
				put_pixel(c, x - 1 + d[0], y - 1 + d[1], color);
		}
	}
}

void	render_hotbar(t_context *ctxt)
{
	int	p[5];
	int	i;

	p[0] = (ctxt->mlx->screen_width - (9 * 52 + 10)) / 2 - 5;
	p[1] = ctxt->mlx->screen_height - 138;
	p[2] = 9 * 52 + 20;
	p[3] = 70;
	p[4] = 0x2E2E2E;
	fill_rect(ctxt, p);
	i = 0;
	while (i < 9)
	{
		draw_slot(ctxt, p[0] + 10 + i * 52, p[1] + 10, i == 0);
		i++;
	}
	draw_item_icon(ctxt, p[0] + 10, p[1] + 10);
}

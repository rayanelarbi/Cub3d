/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:00:00 by rlarbi            #+#    #+#             */
/*   Updated: 2026/02/02 10:13:06 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct s_draw_line_params
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_draw_line_params;

typedef struct s_line_params
{
	int	dx;
	int	dy;
	int	step_x;
	int	step_y;
	int	err;
}	t_line_params;

typedef struct s_tex_render
{
	t_texture	*tex;
	int			tex_x;
}	t_tex_render;

typedef struct s_draw_params
{
	int	x;
	int	draw_start;
	int	draw_end;
	int	line_height;
	int	unclipped_start;
}	t_draw_params;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_ray;

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	draw_textured_column(t_context *ctxt, t_ray *ray, int x,
			t_draw_params *params);
void	draw_vertical_line(t_context *ctxt, t_ray *ray, t_draw_params *p);
void	init_ray(t_ray *ray, t_player *pl, int x, int screen_w);
int		perform_dda(t_ray *ray, t_context *ctxt);
void	calc_wall_params(t_ray *ray, int *line_h,
			int *draw_limits, int screen_h);
void	cast_one_ray(t_context *ctxt, int x);

/* Raycast init utilities */
void	calculate_delta_distances(t_ray *ray);
void	setup_step_and_side_dist_x(t_ray *ray, t_player *pl);
void	setup_step_and_side_dist_y(t_ray *ray, t_player *pl);
void	perform_dda_step(t_ray *ray);

#endif

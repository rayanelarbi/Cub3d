/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:37:51 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 15:37:51 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# define FIRE_0				"./assets/animations/fire_0.xpm"
# define FIRE_1				"./assets/animations/fire_1.xpm"
# define FIRE_2				"./assets/animations/fire_2.xpm"
# define FIRE_3				"./assets/animations/fire_3.xpm"
# define FIRE_4				"./assets/animations/fire_4.xpm"
# define FIRE_5				"./assets/animations/fire_5.xpm"
# define FIRE_6				"./assets/animations/fire_6.xpm"
# define FIRE_7				"./assets/animations/fire_7.xpm"

/* Texture mapping utilities */
int		calc_texture_x(t_ray *ray, double wall_x, int tex_width);
double	calc_initial_tex_pos(t_draw_params *params, double step);
int		clamp_tex_y(int tex_y, int tex_height);
int		get_texture_pixel(t_texture *tex, int tex_x, int tex_y);

#endif /* TEXTURE_H */

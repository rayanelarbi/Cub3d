/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:57:21 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/02 10:10:06 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <../mlx_linux/mlx.h>
# include <unistd.h>

# include "types.h"
# include "raycast.h"

/* Structure initialization */
void		initialize_ctxt(t_context *ctxt, t_game *game, t_player *player);

/* Mlx related functions */
int			initialize_mlx(char *filename, t_context *ctxt);

/* App/menu loop and control */
int			attempt_start_game(t_context *ctxt);

/* Rendering */
int			render_game(t_context *ctxt);
int			render_raycast(t_context *ctxt);

/* Textures (XPM) */
int			load_xpm_into_texture(t_mlx *mlx, const char *path, t_texture *out);
void		destroy_texture(t_mlx *mlx, t_texture *tex);
int			draw_texture(t_context *ctxt, t_texture *tex, int x, int y);

/* Free structures */
int			free_structs(t_context *ctxt);
void		cleanup_context(t_context *ctxt);
void		free_mlx(t_context *ctxt);
void		free_map_info(t_map_info *mi);
void		free_map_grid(char **map, int height);
void		free_game_maps(t_context *ctxt);

#endif /* CUB3D_H */

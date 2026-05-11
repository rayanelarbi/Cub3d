/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:01:00 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/02 09:56:11 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_list	t_list;

/* Basic 3d position structure */
typedef struct s_pos
{
	float				x;
	float				y;
}						t_pos;

/* Basic vector structure */
typedef struct s_vec
{
	float				x;
	float				y;
}						t_vec;

/* Contains all mlx data */
typedef struct s_mlx
{
	void				*mlx;
	void				*mlx_win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					screen_width;
	int					screen_height;
	int					music_pid;
	int					intro_sound_pid;
	void				*hotbar_item_img;
	char				*hotbar_item_addr;
	int					hotbar_item_w;
	int					hotbar_item_h;
}						t_mlx;

/* Used to collect map info */
typedef struct s_collect_state
{
	char	*line;
	size_t	len;
	size_t	cap;
	char	**lines;
	size_t	count;
	size_t	caparr;
	int		in_map;
	size_t	maxw;
}	t_collect_state;

typedef struct s_map_collect
{
	int		fd;
	char	*line;
	t_list	*head;
	size_t	maxw;
	int		in_map;
}	t_map_collect;

/* Contains info on retrieved texture data from input file */
typedef struct s_texture
{
	char				*path;
	void				*img;
	char				*addr;
	int					width;
	int					height;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_texture;

/* Contains map info retrieved from input file */
typedef struct s_map_info
{
	char				*filename;
	struct s_texture	textures[4];
	int					floor_color;
	int					ceiling_color;
}						t_map_info;

/* Contains overall game data */
typedef struct s_game
{
	int					height;
	int					width;
	char				**map;
	char				**map_dup;
	struct s_pos		starting_position;
	char				starting_direction;
	struct s_map_info	map_info;
}						t_game;

/* Contains playr information */
typedef struct s_player
{
	struct s_pos		pos;
	struct s_vec		dir;
	struct s_vec		plane;
	float				move_speed;
	float				rot_speed;
	int					moving_forward;
	int					moving_backward;
	int					moving_left;
	int					moving_right;
	int					turning_left;
	int					turning_right;
	int					action_key;
	int					mouse_x;
	int					mouse_y;
	float				mouse_sensitivity;
}						t_player;

typedef enum e_app_state
{
	APP_PLAYING,
	APP_PAUSED,
}						t_app_state;

/* Main structure containing needed data for program to run */
typedef struct s_context
{
	struct s_mlx		*mlx;
	struct s_game		*game;
	struct s_player		*player;
	t_app_state			state;
}						t_context;

#endif /* TYPES_H */

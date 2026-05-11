/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:41:49 by boschwie          #+#    #+#             */
/*   Updated: 2026/02/01 15:41:49 by boschwie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>

# include "../core/types.h"
# include "../utils/utils.h"

/* Arguments validation */
int			check_extension(char *filename);
int			validate_arguments(t_context *ctxt, char *filename);

/* File parsing */
int			get_textures(char *filename, t_map_info *map_info);
int			get_map(char *filename, t_game *game);
int			parse_file(char *filename, t_game *game);

/* RGB and color parsing */
int			parse_rgb_triplet(const char *s, int *out_color);

/* Config parsing */
int			set_color(struct s_map_info *map_info, char **parts,
				int *found_colors);
int			texture_index(char *key);
int			set_texture(struct s_map_info *map_info, char **parts, int *found);
int			process_config_line(char *line, struct s_map_info *map_info,
				int *found_textures, int *found_colors);

/* Config validation */
int			validate_config(struct s_map_info *map_info, int found_textures,
				int found_colors, char *filename);

/* Map parsing and validation */
int			parse_map(t_list *lines, t_game *game);
int			find_and_set_player(struct s_game *game);
int			validate_map_characters(t_game *game);
int			validate_map_borders(t_game *game);
int			validate_map_closed(struct s_game *game);

/* Line and map utilities */
char		**collect_map_lines(const char *filename, size_t *out_count,
				size_t *out_maxw);
int			is_map_line(char *s);
int			is_valid_map_char(char c);

/* Map reading and building */
int			read_map_lines(int fd, t_list **head, size_t *maxw, int *in_map);
char		*pad_single_line(const char *line, size_t maxw);
char		**pad_lines_to_map(char **lines, size_t count, size_t maxw);
int			build_map(t_list *lines, t_game *game);

/* Map reader utilities */
void		strip_eol(char *s);
void		clear_nodes_keep_content(t_list **head);
char		**list_to_array(t_list *head, size_t *out_count);
void		cleanup_collect(t_map_collect *mc, char **arr);

/* Parser config utilities */
int			assign_texture(struct s_map_info *map_info, int idx, char *path,
				int *found);
int			assign_door_texture(struct s_map_info *map_info, char *path);

#endif /* PARSER_H */

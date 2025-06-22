/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:22:24 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/22 19:28:43 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "parsing_errors.h"
# include "scene_structs.h"
# include <stdbool.h>

char			*skip_whitespace(char *str);
char			*parse_float(char *str, float *value);
char			*parse_uint(char *str, unsigned int *value);
char			*parse_coord(char *str, t_coord *coord);
char			*parse_rgb(char *str, t_RGB *color);
t_parsing_error	parse_cylinder(char *line, t_scene *scene);
t_parsing_error	parse_sphere(char *line, t_scene *scene);
t_parsing_error	parse_camera(char *line, t_camera *camera);
t_parsing_error	parse_ambient_lighting(char *line, t_ambient_lighting *ambient);
t_parsing_error	parse_light(char *line, t_scene *scene);
t_parsing_error	parse_plane(char *line, t_scene *scene);
t_parsing_error	parse_cone(char *line, t_scene *scene);
void			exit_with_error(t_parsing_error error, const char *filename,
					int num_line);
bool			ft_isblank(char character);
bool			not_valid_final_line(const char *line);
bool			check_rgb(t_RGB color);
bool			check_orientation(t_orientation orientation);

void			parse_scene(const char *filename, t_scene *scene);
void			free_scene(t_scene *scene);

t_parsing_error	load_bmp_heightmap(const char *filename, t_heightmap *hmap);
void			free_heightmap(t_heightmap *hmap);
t_parsing_error	parse_heightmap(char *line, t_heightmap **heightmap);

char			*parse_rgb_with_damier(char *str, t_RGB *color,
					t_damier **damier);
bool			char_is_blank(char *str);
void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif // PARSER_H

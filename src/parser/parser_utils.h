/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:00:33 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/17 21:46:43 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include "parsing_errors.h"
# include "scene_structs.h"
# include <stdbool.h>

enum
{
	BASE = 10
};

char			*skip_whitespace(char *str);
char			*parse_float(char *str, float *value);
char			*parse_uint(char *str, unsigned int *value);
char			*parse_coord(char *str, t_coord *coord);
char			*parse_rgb(char *str, t_RGB *color);
t_parsing_error	parse_cylinder(char *line, t_scene *scene);
t_parsing_error	parse_sphere(char *line, t_scene *scene);
t_parsing_error	parse_camera(char *line, t_camera *camera);
t_parsing_error	parse_ambient_lighting(char *line, t_ambient_lighting *ambient);
t_parsing_error	parse_light(char *line, t_light *light);
t_parsing_error	parse_plane(char *line, t_scene *scene);
void			exit_with_error(t_parsing_error error, const char *filename,
					int num_line);
bool			ft_isspace(char character);
bool			not_valid_final_line(const char *line);
bool			check_RGB(t_RGB color);
bool			check_orientation(t_orientation orientation);

#endif // PARSER_UTILS_H

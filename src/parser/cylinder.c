/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:12:48 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/17 20:53:32 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "parsing_errors.h"
#include "scene_structs.h"
#include <stdlib.h>

t_parsing_error	parse_add_cylinder(t_cylinder *cylinder, char *line)
{
	line = skip_whitespace(line + 2);
	line = parse_coord(line, &cylinder->pos);
	if (!line)
		return (ERR_INVALID_CYLINDER_POSITION);
	line = parse_coord(line, &cylinder->axis);
	if (!line)
		return (ERR_INVALID_CYLINDER_AXIS);
	line = parse_float(line, &cylinder->diameter);
	if (!line)
		return (ERR_INVALID_CYLINDER_DIAMETER);
	line = parse_float(line, &cylinder->height);
	if (!line)
		return (ERR_INVALID_CYLINDER_HEIGHT);
	line = parse_rgb(line, &cylinder->color);
	if (!line || cylinder->color.r > RGB_MAX || cylinder->color.g > RGB_MAX
		|| cylinder->color.b > RGB_MAX)
		return (ERR_INVALID_CYLINDER_COLOR);
	return (NO_ERROR);
}

t_parsing_error	parse_cylinder(char *line, t_scene *scene)
{
	t_cylinder		cylinder;
	t_cylinder		*new_cylinders;
	t_parsing_error	error;

	error = parse_add_cylinder(&cylinder, line);
	if (error != NO_ERROR)
		return (error);
	new_cylinders = realloc(scene->cylinders, sizeof(t_cylinder)
			* (scene->cylinder_count + 1));
	if (!new_cylinders)
		return (ERR_MEMORY_ALLOCATION);
	scene->cylinders = new_cylinders;
	scene->cylinders[scene->cylinder_count++] = cylinder;
	return (NO_ERROR);
}

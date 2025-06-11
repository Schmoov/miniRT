/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:12:48 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/11 20:11:20 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/miniRT.h"

t_parsing_error	parse_add_cylinder(t_cylinder *cylinder, char *line)
{
	t_parsing_error	err;

	line = skip_whitespace(line + 2);
	line = parse_coord(line, &cylinder->pos);
	if (!line)
		return (ERR_INVALID_CYLINDER_POSITION);
	line = parse_coord(line, &cylinder->axis);
	if (!line || !check_orientation(cylinder->axis))
		return (ERR_INVALID_CYLINDER_AXIS);
	line = parse_float(line, &cylinder->diameter);
	if (!line)
		return (ERR_INVALID_CYLINDER_DIAMETER);
	line = parse_float(line, &cylinder->height);
	if (!line)
		return (ERR_INVALID_CYLINDER_HEIGHT);
	line = parse_rgb_with_damier(line, &cylinder->color, &cylinder->damier);
	if (!check_rgb(cylinder->color))
		return (ERR_INVALID_CYLINDER_COLOR);
	if (not_valid_final_line(line))
	{
		err = parse_heightmap(line, &cylinder->heightmap);
		if (err != NO_ERROR)
			return (err);
	}
	return (NO_ERROR);
}

t_parsing_error	parse_cylinder(char *line, t_scene *scene)
{
	t_cylinder		*new_cylinders;
	t_parsing_error	error;

	t_cylinder (cylinder) = {0};
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

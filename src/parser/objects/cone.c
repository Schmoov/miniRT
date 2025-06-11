/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:00:00 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/11 19:12:18 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/miniRT.h"
#include "../../../inc/parser.h"
#include "../../../inc/parsing_errors.h"
#include "../../../inc/scene_structs.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

bool	check_cone_angle(float angle)
{
	return (angle > 0.0F && angle < 180);
}

t_parsing_error	parse_add_cone(t_cone *cone, char *line)
{
	line = skip_whitespace(line + 2);
	line = parse_coord(line, &cone->pos);
	if (!line)
		return (ERR_INVALID_CONE_POSITION);
	line = parse_coord(line, &cone->axis);
	if (!line || !check_orientation(cone->axis))
		return (ERR_INVALID_CONE_AXIS);
	line = parse_float(line, &cone->angle);
	if (!line || !check_cone_angle(cone->angle))
		return (ERR_INVALID_CONE_ANGLE);
	line = parse_float(line, &cone->height);
	if (!line)
		return (ERR_INVALID_CONE_HEIGHT);
	line = parse_rgb_with_damier(line, &cone->color, &cone->damier);
	if (!check_rgb(cone->color))
		return (ERR_INVALID_CONE_COLOR);
	if (not_valid_final_line(line))
		return (parse_heightmap(line, &cone->heightmap));
	return (NO_ERROR);
}

t_parsing_error	parse_cone(char *line, t_scene *scene)
{
	t_cone			*new_cones;
	t_parsing_error	error;

	t_cone(cone) = {0};
	error = parse_add_cone(&cone, line);
	if (error != NO_ERROR)
		return (error);
	new_cones = realloc(scene->cones, sizeof(t_cone) * (scene->cone_count + 1));
	if (!new_cones)
		return (ERR_MEMORY_ALLOCATION);
	scene->cones = new_cones;
	scene->cones[scene->cone_count++] = cone;
	return (NO_ERROR);
}

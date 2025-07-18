/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:00:00 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/22 19:29:21 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/miniRT.h"
#include "../../../inc/parser.h"
#include "../../../inc/parsing_errors.h"
#include "../../../inc/scene_structs.h"

bool	check_cone_angle(float angle)
{
	return (angle > 0.0F && angle < 180);
}

t_parsing_error	parse_add_cone(t_cone *cone, char *line)
{
	t_parsing_error	err;

	line = skip_whitespace(line + 2);
	line = parse_coord(line, &cone->pos);
	if (!line)
		return (ERR_INVALID_CONE_POSITION);
	line = parse_coord(line, &cone->axis);
	if (!line || !check_orientation(cone->axis))
		return (ERR_INVALID_CONE_AXIS);
	line = parse_float(line, &cone->angle);
	if (!char_is_blank(line) || !check_cone_angle(cone->angle))
		return (ERR_INVALID_CONE_ANGLE);
	line = parse_float(line, &cone->height);
	if (!char_is_blank(line) || cone->height <= 0.0F)
		return (ERR_INVALID_CONE_HEIGHT);
	line = parse_rgb_with_damier(line, &cone->color, &cone->damier);
	if (!line || !check_rgb(cone->color))
		return (ERR_INVALID_CONE_COLOR);
	if (not_valid_final_line(line))
	{
		err = parse_heightmap(line, &cone->heightmap);
		if (err != NO_ERROR)
			return (err);
	}
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
	new_cones = ft_realloc(scene->cones, sizeof(t_cone) * (scene->cone_count),
			sizeof(t_cone) * (scene->cone_count + 1));
	if (!new_cones)
		return (ERR_MEMORY_ALLOCATION);
	scene->cones = new_cones;
	scene->cones[scene->cone_count++] = cone;
	return (NO_ERROR);
}

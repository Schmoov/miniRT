/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:45:09 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/17 21:30:48 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "parsing_errors.h"
#include "scene_structs.h"
#include <stdlib.h>

t_parsing_error	parse_plane(char *line, t_scene *scene)
{
	t_plane	plane;
	t_plane	*new_planes;

	line = skip_whitespace(line + 2);
	line = parse_coord(line, &plane.pos);
	if (!line)
		return (ERR_INVALID_PLANE_POSITION);
	line = parse_coord(line, &plane.axis);
	if (!line)
		return (ERR_INVALID_PLANE_AXIS);
	line = parse_rgb(line, &plane.color);
	if (not_valid_final_line(line) || !check_RGB(plane.color))
		return (ERR_INVALID_PLANE_COLOR);
	new_planes = realloc(scene->planes, sizeof(t_plane) * (scene->plane_count
				+ 1));
	if (!new_planes)
		return (ERR_MEMORY_ALLOCATION);
	scene->planes = new_planes;
	scene->planes[scene->plane_count++] = plane;
	return (NO_ERROR);
}

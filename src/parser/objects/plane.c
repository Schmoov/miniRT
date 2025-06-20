/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:45:09 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/15 14:57:01 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/miniRT.h"

t_parsing_error	parse_plane(char *line, t_scene *scene)
{
	t_parsing_error(err) = NO_ERROR;
	t_plane(plane) = {0};
	line = skip_whitespace(line + 2);
	line = parse_coord(line, &plane.pos);
	if (!line)
		return (ERR_INVALID_PLANE_POSITION);
	line = parse_coord(line, &plane.axis);
	if (!line || !check_orientation(plane.axis))
		return (ERR_INVALID_PLANE_AXIS);
	line = parse_rgb_with_damier(line, &plane.color, &plane.damier);
	if (!line || !check_rgb(plane.color))
		return (ERR_INVALID_PLANE_COLOR);
	if (line && ft_isalpha(*line))
	{
		err = parse_heightmap(line, &plane.heightmap);
		if (err != NO_ERROR)
			return (err);
	}
	t_plane *(new_planes) = realloc(scene->planes, sizeof(t_plane)
			* (scene->plane_count + 1));
	if (!new_planes)
		return (ERR_MEMORY_ALLOCATION);
	scene->planes = new_planes;
	scene->planes[scene->plane_count++] = plane;
	return (NO_ERROR);
}

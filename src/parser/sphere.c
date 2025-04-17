/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:19:38 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/17 22:53:22 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "parsing_errors.h"
#include "scene_structs.h"
#include <stdlib.h>

t_parsing_error	parse_sphere(char *line, t_scene *scene)
{
	t_sphere	sphere;
	t_sphere	*temp;

	line = skip_whitespace(line + 2);
	line = parse_coord(line, &sphere.pos);
	if (!line)
		return (ERR_INVALID_SPHERE_POSITION);
	line = parse_float(line, &sphere.diameter);
	if (!line)
		return (ERR_INVALID_SPHERE_DIAMETER);
	line = parse_rgb(line, &sphere.color);
	if (not_valid_final_line(line) || !check_rgb(sphere.color))
		return (ERR_INVALID_SPHERE_COLOR);
	temp = realloc(scene->spheres, sizeof(t_sphere) * (scene->sphere_count
				+ 1));
	if (!temp)
		return (ERR_MEMORY_ALLOCATION);
	scene->spheres = temp;
	scene->spheres[scene->sphere_count++] = sphere;
	return (NO_ERROR);
}

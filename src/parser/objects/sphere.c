/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:19:38 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/11 20:21:52 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/miniRT.h"

t_parsing_error	parse_sphere(char *line, t_scene *scene)
{
	t_sphere(sphere) = {0};
	t_parsing_error(err) = NO_ERROR;
	line = skip_whitespace(line + 2);
	line = parse_coord(line, &sphere.pos);
	if (!line)
		return (ERR_INVALID_SPHERE_POSITION);
	line = parse_float(line, &sphere.diameter);
	if (!line)
		return (ERR_INVALID_SPHERE_DIAMETER);
	line = parse_rgb_with_damier(line, &sphere.color, &sphere.damier);
	if (!check_rgb(sphere.color))
		return (ERR_INVALID_SPHERE_COLOR);
	if (not_valid_final_line(line))
	{
		err = parse_heightmap(line, &sphere.heightmap);
		if (err != NO_ERROR)
			return (err);
	}
	t_sphere *(temp) = realloc(scene->spheres, sizeof(t_sphere)
			* (scene->sphere_count + 1));
	if (!temp)
		return (ERR_MEMORY_ALLOCATION);
	scene->spheres = temp;
	scene->spheres[scene->sphere_count++] = sphere;
	return (NO_ERROR);
}

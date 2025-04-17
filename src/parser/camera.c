/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:45:58 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/17 21:33:48 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "parsing_errors.h"
#include "scene_structs.h"
#include <stdbool.h>
#include <stdlib.h>

bool	not_valid_final_line(const char *line)
{
	return (!line || (!ft_isspace(*line) && *line != '\0'));
}

bool	check_orientation(t_orientation orientation)
{
	return (orientation.x >= -1 && orientation.x <= 1 && orientation.y >= -1
		&& orientation.y <= 1 && orientation.z >= -1 && orientation.z <= 1);
}

bool	check_fov(float fov)
{
	return (fov >= 0 && fov <= FOV_MAX);
}

t_parsing_error	parse_camera(char *line, t_camera *camera)
{
	static int	cpt = 0;

	if (cpt != 0)
		return (ERR_INVALID_CAMERA_DUPLICATE);
	line = skip_whitespace(line + 1);
	line = parse_coord(line, &camera->pos);
	if (!line)
		return (ERR_INVALID_CAMERA_POSITION);
	line = parse_coord(line, &camera->orientation);
	if (!line || !check_orientation(camera->orientation))
		return (ERR_INVALID_CAMERA_ORIENTATION);
	line = parse_float(line, &camera->fov);
	if (!check_fov(camera->fov) || not_valid_final_line(line))
		return (ERR_INVALID_CAMERA_FOV);
	cpt++;
	return (NO_ERROR);
}

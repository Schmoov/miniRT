/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:45:58 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/17 00:03:39 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "parsing_errors.h"
#include "scene_structs.h"

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
	if (!line)
		return (ERR_INVALID_CAMERA_ORIENTATION);
	line = parse_float(line, &camera->fov);
	if (!line || camera->fov < 0 || camera->fov > FOV_MAX)
		return (ERR_INVALID_CAMERA_FOV);
	cpt++;
	return (NO_ERROR);
}

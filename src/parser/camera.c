/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:45:58 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/11 20:00:11 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

bool	not_valid_final_line(const char *line)
{
	if (!line)
		return (true);
	while (*line && ft_isspace(*line))
		line++;
	return (*line != '\0');
}

bool	check_orientation(t_orientation orientation)
{
	float	magnitude;

	magnitude = sqrt((orientation.x * orientation.x) + (orientation.y
				* orientation.y) + (orientation.z * orientation.z));
	return (fabs(magnitude - 1.0F) < 0.00001F);
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

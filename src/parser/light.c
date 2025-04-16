/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:45:39 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/16 23:21:22 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "parsing_errors.h"
#include "scene_structs.h"

t_parsing_error	parse_light(char *line, t_light *light)
{
	line = skip_whitespace(line + 1);
	line = parse_coord(line, &light->pos);
	if (!line)
		return (ERR_INVALID_LIGHT_POSITION);
	line = parse_float(line, &light->brightness);
	if (!line || light->brightness < 0.0 || light->brightness > 1.0)
		return (ERR_INVALID_LIGHT_BRIGHTNESS);
	line = parse_rgb(line, &light->color);
	if (!line || light->color.r > RGB_MAX || light->color.g > RGB_MAX
		|| light->color.b > RGB_MAX)
		return (ERR_INVALID_LIGHT_COLOR);
	return (NO_ERROR);
}

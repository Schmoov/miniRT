/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:45:39 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/18 19:12:10 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_parsing_error	parse_light(char *line, t_scene *scene)
{
	t_light	*new_lights;

	t_light(light) = {0};
	line = skip_whitespace(line + 1);
	line = parse_coord(line, &light.pos);
	if (!line)
		return (ERR_INVALID_LIGHT_POSITION);
	line = parse_float(line, &light.brightness);
	if (!line || light.brightness < 0.0 || light.brightness > 1.0)
		return (ERR_INVALID_LIGHT_BRIGHTNESS);
	line = parse_rgb(line, &light.color);
	if (!char_is_blank(line) || !check_rgb(light.color))
		return (ERR_INVALID_LIGHT_COLOR);
	line = skip_whitespace(line);
	if (not_valid_final_line(line))
		return (ERR_INVALID_LIGHT_COLOR);
	new_lights = realloc(scene->lights, sizeof(t_light) * (scene->light_count
				+ 1));
	if (!new_lights)
		return (ERR_MEMORY_ALLOCATION);
	scene->lights = new_lights;
	scene->lights[scene->light_count++] = light;
	return (NO_ERROR);
}

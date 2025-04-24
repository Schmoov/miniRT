/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:45:39 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/24 14:57:48 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_parsing_error	parse_light(char *line, t_light *light)
{
	static int	cpt = 0;

	if (cpt != 0)
		return (ERR_INVALID_LIGHT_DUPLICATE);
	line = skip_whitespace(line + 1);
	line = parse_coord(line, &light->pos);
	if (!line)
		return (ERR_INVALID_LIGHT_POSITION);
	line = parse_float(line, &light->brightness);
	if (!line || light->brightness < 0.0 || light->brightness > 1.0)
		return (ERR_INVALID_LIGHT_BRIGHTNESS);
	line = parse_rgb(line, &light->color);
	if (not_valid_final_line(line) || !check_rgb(light->color))
		return (ERR_INVALID_LIGHT_COLOR);
	cpt++;
	return (NO_ERROR);
}

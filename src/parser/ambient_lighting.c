/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:46:59 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/18 19:09:57 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

bool	check_rgb(t_RGB color)
{
	return (color.r >= 0 && color.r <= RGB_MAX && color.g >= 0
		&& color.g <= RGB_MAX && color.b >= 0 && color.b <= RGB_MAX);
}

t_parsing_error	parse_ambient_lighting(char *line, t_ambient_lighting *ambient)
{
	static int	cpt = 0;

	if (cpt != 0)
		return (ERR_INVALID_AMBIENT_DUPLICATE);
	line = skip_whitespace(line + 1);
	line = parse_float(line, &ambient->ratio);
	if (!line || ambient->ratio < 0.0 || ambient->ratio > 1.0)
		return (ERR_INVALID_AMBIENT_RATIO);
	line = parse_rgb(line, &ambient->color);
	if (!line || !check_rgb(ambient->color))
		return (ERR_INVALID_AMBIENT_COLOR);
	line = skip_whitespace(line);
	if (!char_is_blank(line))
		return (ERR_INVALID_AMBIENT_COLOR);
	cpt++;
	return (NO_ERROR);
}

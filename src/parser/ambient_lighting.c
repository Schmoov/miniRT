/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:46:59 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/17 00:03:44 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"
#include "parsing_errors.h"
#include "scene_structs.h"

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
	if (!line || ambient->color.r > RGB_MAX || ambient->color.g > RGB_MAX
		|| ambient->color.b > RGB_MAX)
		return (ERR_INVALID_AMBIENT_COLOR);
	cpt++;
	return (NO_ERROR);
}

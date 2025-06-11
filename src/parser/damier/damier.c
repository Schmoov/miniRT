/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:43:28 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/11 19:04:58 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/parser.h"
#include <stdlib.h>

static t_RGB	*copy_rgb(t_RGB *dest, const t_RGB *src)
{
	if (!dest || !src)
		return (NULL);
	dest->r = src->r;
	dest->g = src->g;
	dest->b = src->b;
	return (dest);
}

char	*parse_damier(char *str, t_RGB *color1, t_damier **damier_ptr)
{
	t_damier	*damier;

	damier = malloc(sizeof(t_damier));
	if (!damier)
		return (NULL);
	damier->color1.r = color1->r;
	damier->color1.g = color1->g;
	damier->color1.b = color1->b;
	str = parse_uint(str, &damier->color2.r);
	if (!str || *str++ != ',')
		return (free(damier), NULL);
	str = parse_uint(str, &damier->color2.g);
	if (!str || *str++ != ',')
		return (free(damier), NULL);
	str = parse_uint(str, &damier->color2.b);
	*damier_ptr = damier;
	return (skip_whitespace(str));
}

char	*parse_rgb_with_damier(char *str, t_RGB *color, t_damier **damier)
{
	str = parse_uint(str, &color->r);
	if (!str || *str++ != ',')
		return (NULL);
	str = parse_uint(str, &color->g);
	if (!str || *str++ != ',')
		return (NULL);
	str = parse_uint(str, &color->b);
	if (!str || *str++ != ':')
		return (skip_whitespace(str));
	return (parse_damier(str, color, damier));
}

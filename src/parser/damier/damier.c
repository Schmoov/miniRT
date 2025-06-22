/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:43:28 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/22 19:20:16 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/parser.h"
#include <stdlib.h>

char	*parse_damier(char *str, t_RGB *color1, t_damier **damier_ptr)
{
	t_damier	*damier;

	str = skip_whitespace(str);
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
	if (str == NULL || !ft_isblank(*str))
		return (free(damier), NULL);
	*damier_ptr = damier;
	return (skip_whitespace(str));
}

char	*parse_rgb_with_damier(char *str, t_RGB *color, t_damier **damier)
{
	*damier = NULL;
	str = parse_uint(str, &color->r);
	if (!str || *str++ != ',')
		return (NULL);
	str = parse_uint(str, &color->g);
	if (!str || *str++ != ',')
		return (NULL);
	str = parse_uint(str, &color->b);
	if (!str)
		return (NULL);
	if (*str == ':')
	{
		str++;
		return (parse_damier(str, color, damier));
	}
	if (*str && !ft_isblank(*str))
		return (NULL);
	return (skip_whitespace(str));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/05/04 14:12:01 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

static void	color_clamp(int *c)
{
	if (*c > 255)
		*c = 255;
	if (c < 0)
		*c = 0;
}

t_rgb	color_mult(t_rgb c1, t_rgb c2)
{
	int	r;
	int	g;
	int	b;

	r = (((c1 & RED) >> 16) * ((c2 & RED) >> 16)) / 255;
	color_clamp(&r);
	g = (((c1 & GRN) >> 8) * ((c2 & GRN) >> 8)) / 255;
	color_clamp(&g);
	b = ((c1 & BLU) * (c2 & BLU)) / 255;
	color_clamp(&b);
	return (r | g | b);
}

t_rgb	color_add(t_rgb c1, t_rgb c2)
{
	int	r;
	int	g;
	int	b;

	r = ((c1 & RED) >> 16) + ((c2 & RED) >> 16);
	color_clamp(&r);
	g = ((c1 & GRN) >> 8) + ((c2 & GRN) >> 8);
	color_clamp(&g);
	b = (c1 & BLU) + (c2 & BLU);
	color_clamp(&b);
	return (r | g | b);
}

t_rgb	color_scale(t_rgb c, float f)
{
	int	r;
	int	g;
	int	b;

	r = ((c & RED) >> 16) * f;
	color_clamp(&r);
	g = ((c & GRN) >> 8) * f;
	color_clamp(&g);
	b = (c & BLU) * f;
	color_clamp(&b);
	return (r | g | b);
}

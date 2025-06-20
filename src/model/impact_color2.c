/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact_color2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:39:57 by parden            #+#    #+#             */
/*   Updated: 2025/06/20 14:30:26 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_rgb	color_cyl(t_model *m, t_impact *imp, t_cyl *obj)
{
	t_v3	vec;
	int		f2;
	int		f3;

	(void) m;
	if (!obj->check)
		return (obj->col1);
	vec_sub(vec, imp->pos, obj->pos);
	f2 = roundf(6.5f * vec_dot(vec, obj->ax) / obj->hgt);
	vec_normalize(vec);
	f3 = roundf(4 * atan2f(vec_dot(vec, obj->e2),
				vec_dot(vec, obj->e3)) / M_PI);
	if ((f2 + f3) % 2)
		return (obj->col1);
	return (obj->col2);
}

t_rgb	color_con(t_model *m, t_impact *imp, t_con *obj)
{
	t_v3	vec;
	int		f2;
	int		f3;

	(void) m;
	if (!obj->check)
		return (obj->col1);
	vec_sub(vec, imp->pos, obj->pos);
	f2 = roundf(6.5f * vec_dot(vec, obj->ax) / obj->hgt);
	vec_normalize(vec);
	f3 = roundf(4 * atan2f(vec_dot(vec, obj->e2),
				vec_dot(vec, obj->e3)) / M_PI);
	if ((f2 + f3) % 2)
		return (obj->col1);
	return (obj->col2);
}

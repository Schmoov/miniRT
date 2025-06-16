/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact_color1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:39:57 by parden            #+#    #+#             */
/*   Updated: 2025/06/16 17:17:41 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_rgb	color_plane(t_model *m, t_impact *imp, t_pla *obj)
{
	t_v3	vec;
	int		f2;
	int		f3;

	if (!obj->check)
		return (obj->col1);
	vec_sub(vec, imp->pos, obj->pos);
	f2 = roundf(vec_dot(obj->e2, vec));
	f3 = roundf(vec_dot(obj->e3, vec));
	if ((f2 + f3) % 2)
		return (obj->col1);
	return (obj->col2);
}

t_rgb	color_disk(t_model *m, t_impact *imp, t_dsk *obj)
{
	t_v3	vec;
	int		f2;
	int		f3;

	if (!obj->check)
		return (obj->col1);
	vec_sub(vec, imp->pos, obj->pos);
	f2 = roundf(2 * vec_dot(obj->e2, vec) / obj->rad);
	f3 = roundf(2 * vec_dot(obj->e3, vec) / obj->rad);
	if ((f2 + f3) % 2)
		return (obj->col1);
	return (obj->col2);
}

t_rgb	color_sphere(t_model *m, t_impact *imp, t_sph *obj)
{
	t_v3	vec;
	int		f2;
	int		f3;

	if (!obj->check)
		return (obj->col1);
	vec_sub(vec, imp->pos, obj->pos);
	vec_normalize(vec);
	f2 = roundf(8 * acosf(vec[1]) / M_PI);
	f3 = roundf(8 * atan2f(vec[2], vec[0]) / M_PI);
	if ((f2 + f3) % 2)
		return (obj->col1);
	return (obj->col2);
}

void	impact_color(t_model *m, t_impact *imp)
{
	t_obj	*obj;

	obj = &(m->obj[imp->obj_idx]);
	if (obj->type == PLA)
		imp->col = color_plane(m, imp, &obj->pla);
	if (obj->type == SPH)
		imp->col = color_sphere(m, imp, &obj->sph);
	if (obj->type == CYL)
		imp->col = color_cyl(m, imp, &obj->cyl);
	if (obj->type == CON)
		imp->col = color_con(m, imp, &obj->con);
	if (obj->type == DSK)
		imp->col = color_disk(m, imp, &obj->dsk);
}

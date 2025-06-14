/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact_color1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:39:57 by parden            #+#    #+#             */
/*   Updated: 2025/06/14 18:15:49 by parden           ###   ########.fr       */
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
	if ((f2+f3)%2)
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
		imp->col = obj->sph.col1;
	if (obj->type == CYL)
		imp->col = obj->cyl.col1;
	if (obj->type == CON)
		imp->col = obj->con.col1;
	if (obj->type == DSK)
		imp->col = obj->dsk.col1;
}


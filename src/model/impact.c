/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:12:04 by parden            #+#    #+#             */
/*   Updated: 2025/06/20 14:29:51 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static void	normal_cylinder(t_model *m, t_impact *imp, t_obj *obj)
{
	t_v3	comp;

	(void) m;
	vec_sub(imp->normal, imp->pos, obj->cyl.pos);
	ft_memcpy(comp, imp->normal, sizeof(t_v3));
	vec_scale(comp, obj->cyl.ax, vec_dot(imp->normal, obj->cyl.ax));
	vec_sub(imp->normal, imp->normal, comp);
	vec_normalize(imp->normal);
}

static void	normal_cone(t_model *m, t_impact *imp, t_obj *obj)
{
	t_v3	comp;
	float	h;

	(void) m;
	vec_sub(imp->normal, imp->pos, obj->con.pos);
	h = vec_dot(imp->normal, obj->con.ax);
	ft_memcpy(comp, imp->normal, sizeof(t_v3));
	vec_scale(comp, obj->con.ax, h);
	vec_sub(comp, imp->normal, comp);
	vec_scale(imp->normal, obj->con.ax, h * powf(tanf(obj->con.ang), 2));
	vec_sub(imp->normal, comp, imp->normal);
	vec_normalize(imp->normal);
}

void	impact_normal(t_model *m, t_impact *imp)
{
	t_obj	*obj;

	obj = &(m->obj[imp->obj_idx]);
	if (obj->type == PLA)
		ft_memcpy(imp->normal, obj->pla.nor, sizeof(t_v3));
	if (obj->type == DSK)
		ft_memcpy(imp->normal, obj->dsk.nor, sizeof(t_v3));
	if (obj->type == SPH)
	{
		vec_sub(imp->normal, imp->pos, obj->sph.pos);
		vec_normalize(imp->normal);
	}
	if (obj->type == CYL)
		normal_cylinder(m, imp, obj);
	if (obj->type == CON)
		normal_cone(m, imp, obj);
	if (vec_dot(imp->normal, imp->ray.dir) > 0)
		vec_opp(imp->normal);
	bump_normal(m, imp, obj);
}

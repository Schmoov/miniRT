/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:12:04 by parden            #+#    #+#             */
/*   Updated: 2025/06/13 18:14:14 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	impact_color(t_model *m, t_impact *imp)
{
	t_obj	*obj;

	obj = &(m->obj[imp->obj_idx]);
	if (obj->type == PLA)
		imp->col = obj->pla.col;
	if (obj->type == SPH)
		imp->col = obj->sph.col;
	if (obj->type == CYL)
		imp->col = obj->cyl.col;
	if (obj->type == CON)
		imp->col = obj->con.col;
	if (obj->type == DSK)
		imp->col = obj->dsk.col;
}

static void	normal_cylinder(t_model *m, t_impact *imp, t_obj *obj)
{
	t_v3	comp;

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
}

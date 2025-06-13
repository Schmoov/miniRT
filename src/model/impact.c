/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:12:04 by parden            #+#    #+#             */
/*   Updated: 2025/06/13 13:25:38 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	impact_color(t_model *m, t_impact *imp)
{
	//WILL CHANGE
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

void	impact_normal(t_model *m, t_impact *imp)
{
	//WILL CHANGE
	t_obj	*obj;

	obj = &(m->obj[imp->obj_idx]);
	if (obj->type == PLA)
		ft_memcpy(imp->normal, obj->pla.nor, sizeof(t_v3));
	if (obj->type == DSK)
		ft_memcpy(imp->normal, obj->dsk.nor, sizeof(t_v3));
	if (obj->type == SPH)
	{
		ft_memcpy(imp->normal, imp->pos, sizeof(t_v3));
		vec_sub(imp->normal, imp->normal, obj->sph.pos);
		vec_normalize(imp->normal);
	}
	if (obj->type == CYL)
	{
		t_v3	comp;
		ft_memcpy(imp->normal, imp->pos, sizeof(t_v3));
		vec_sub(imp->normal, imp->normal, obj->cyl.pos);
		ft_memcpy(comp, imp->normal, sizeof(t_v3));
		vec_scale(comp, obj->cyl.ax, vec_dot(imp->normal, obj->cyl.ax));
		vec_sub(imp->normal, imp->normal, comp);
		vec_normalize(imp->normal);
	}
	//caca
	if (obj->type == CON)
	{
		t_v3	comp;
		ft_memcpy(imp->normal, imp->pos, sizeof(t_v3));
		vec_sub(imp->normal, imp->normal, obj->con.pos);
		ft_memcpy(comp, imp->normal, sizeof(t_v3));
		vec_scale(comp, obj->con.ax, vec_dot(imp->normal, obj->con.ax));
		vec_sub(imp->normal, imp->normal, comp);
		vec_normalize(imp->normal);
	}

	if (vec_dot(imp->normal, imp->ray.dir) > 0)
		vec_opp(imp->normal);
}

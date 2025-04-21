/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_impact.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:12:04 by parden            #+#    #+#             */
/*   Updated: 2025/04/21 16:24:11 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/model.h"

void	model_impact_object(t_model *m, t_impact *imp, int i)
{
	float	old_scale;
	t_obj	*obj;

	old_scale = imp->scale;
	obj = &(m->obj[i]);
	if (obj->type == PLA)
		model_impact_plane(m, imp, &(obj->pla));
	if (obj->type == SPH)
		model_impact_sphere(m, imp, &(obj->sph));
	if (obj->type == CYL)
		model_impact_cylinder(m, imp, &(obj->cyl));
	if (imp->scale < old_scale)
	{
		imp->obj_idx = i;
		imp->pos[0] = imp->scale * imp->ray.dir[0] + imp->ray.pos[0];
		imp->pos[1] = imp->scale * imp->ray.dir[1] + imp->ray.pos[1];
		imp->pos[2] = imp->scale * imp->ray.dir[2] + imp->ray.pos[2];
	}
}

void	model_impact_plane(t_model *m, t_impact *imp, t_pla *pla)
{
	if (vec_dot(imp->ray.dir, pla->nor) < EPS)
		return;
	float scale = pla->nor[0] * imp->ray.pos[0] - imp->ray.dir[0]
		+ pla->nor[1] * imp->ray.pos[1] - imp->ray.dir[1]
		+ pla->nor[2] * imp->ray.pos[2] - imp->ray.dir[2];
	scale /= vec_dot(imp->ray.dir, pla->nor);
	if (scale > EPS && scale < imp->scale)
		imp->scale = scale;
}

void	model_impact_sphere(t_model *m, t_impact *imp, t_sph *sph)
{
	t_v3	v_cr;
	float	dot2;
	float	delta;
	float	x1;
	float	x2;

	v_cr[0] = imp->ray.pos[0] - sph->pos[0];
	v_cr[1] = imp->ray.pos[1] - sph->pos[1];
	v_cr[2] = imp->ray.pos[2] - sph->pos[2];
	delta = 4 * (vec_dot(imp->ray.dir, v_cr) * vec_dot(imp->ray.dir, v_cr) - (vec_norm2(v_cr) - sph->rad * sph->rad));
	if (delta < EPS)
		return;
	x1 = (-2 * vec_dot(imp->ray.dir, v_cr) + sqrt(delta)) / 2 * vec_norm2(imp->ray.dir);
	x2 = (-2 * vec_dot(imp->ray.dir, v_cr) - sqrt(delta)) / 2 * vec_norm2(imp->ray.dir);
	if (x2 > EPS && x2 < x1)
		x1 = x2;
	if (x1 > EPS && x1 < imp->scale)
		imp->scale = x1;
}

void	model_impact_cylinder(t_model *m, t_impact *imp, t_cyl *cyl)
{
}

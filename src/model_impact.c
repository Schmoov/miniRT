/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_impact.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:12:04 by parden            #+#    #+#             */
/*   Updated: 2025/04/18 19:14:07 by parden           ###   ########.fr       */
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
		imp->obj_idx = i;
}

void	model_impact_plane(t_model *m, t_impact *imp, t_pla *pla)
{
}

void	model_impact_sphere(t_model *m, t_impact *imp, t_sph *sph)
{
}

void	model_impact_cylinder(t_model *m, t_impact *imp, t_cyl *cyl)
{
}

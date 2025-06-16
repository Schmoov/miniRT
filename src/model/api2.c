/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:20:12 by parden            #+#    #+#             */
/*   Updated: 2025/06/16 16:22:52 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	model_add_light(t_model *mod, t_light *l)
{
	int	i;

	i = mod->lit_nb;
	mod->lit[i].pos[0] = l->pos.x;
	mod->lit[i].pos[1] = l->pos.y;
	mod->lit[i].pos[2] = l->pos.z;
	mod->lit[i].col = (l->color.r << 16) | (l->color.g << 8) | l->color.b;
	mod->lit[i].col = color_scale(mod->lit[i].col, l->brightness);
	mod->lit_nb++;
}

void	model_add_plane(t_model *mod, t_plane *p)
{
	t_pla	*obj;

	mod->obj[mod->obj_nb].type = PLA;
	obj = &(mod->obj[mod->obj_nb].pla);
	obj->pos[0] = p->pos.x;
	obj->pos[1] = p->pos.y;
	obj->pos[2] = p->pos.z;
	obj->nor[0] = p->axis.x;
	obj->nor[1] = p->axis.y;
	obj->nor[2] = p->axis.z;
	add_plane_axis(obj);
	model_add_plane_color(p, obj);
	mod->obj_nb++;
}

void	model_add_sphere(t_model *mod, t_sphere *s)
{
	t_sph	*obj;

	mod->obj[mod->obj_nb].type = SPH;
	obj = &(mod->obj[mod->obj_nb].sph);
	obj->pos[0] = s->pos.x;
	obj->pos[1] = s->pos.y;
	obj->pos[2] = s->pos.z;
	obj->rad = s->diameter / 2;
	model_add_sphere_color(s, obj);
	mod->obj_nb++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_api2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:20:12 by parden            #+#    #+#             */
/*   Updated: 2025/05/21 19:33:06 by parden           ###   ########.fr       */
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
	obj->col = (p->color.r << 16) | (p->color.g << 8) | p->color.b;
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
	obj->col = (s->color.r << 16) | (s->color.g << 8) | s->color.b;
	mod->obj_nb++;
}

void	model_add_cylinder(t_model *mod, t_cylinder *c)
{
	t_cyl	*obj;

	mod->obj[mod->obj_nb].type = CYL;
	obj = &(mod->obj[mod->obj_nb].cyl);
	obj->pos[0] = c->pos.x;
	obj->pos[1] = c->pos.y;
	obj->pos[2] = c->pos.z;
	obj->ax[0] = c->axis.x;
	obj->ax[1] = c->axis.y;
	obj->ax[2] = c->axis.z;
	obj->rad = c->diameter / 2;
	obj->hgt = c->height / 2;
	obj->col = (c->color.r << 16) | (c->color.g << 8) | c->color.b;
	mod->obj_nb++;

	t_dsk	*d1;

	mod->obj[mod->obj_nb].type = DSK;
	d1 = &(mod->obj[mod->obj_nb].dsk);
	ft_memcpy(d1->pos, obj->pos, sizeof(t_v3));
	vec_move_along(d1->pos, obj->ax, obj->hgt / 2);
	ft_memcpy(d1->nor, obj->ax, sizeof(t_v3));
	d1->col = obj->col;
	d1->rad = obj->rad;
	mod->obj_nb++;

	t_dsk	*d2;

	mod->obj[mod->obj_nb].type = DSK;
	d2 = &(mod->obj[mod->obj_nb].dsk);
	ft_memcpy(d2->pos, obj->pos, sizeof(t_v3));
	vec_move_along(d2->pos, obj->ax, -obj->hgt / 2);
	ft_memcpy(d2->nor, obj->ax, sizeof(t_v3));
	d2->col = obj->col;
	d2->rad = obj->rad;
	mod->obj_nb++;
}

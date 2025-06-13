/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_api3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:20:12 by parden            #+#    #+#             */
/*   Updated: 2025/06/13 13:00:52 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static void	model_add_cylinder_disk(t_model *mod, t_cyl *cy)
{
	t_dsk	*d;

	mod->obj[mod->obj_nb].type = DSK;
	d = &(mod->obj[mod->obj_nb].dsk);
	ft_memcpy(d->pos, cy->pos, sizeof(t_v3));
	vec_move_along(d->pos, cy->ax, cy->hgt);
	ft_memcpy(d->nor, cy->ax, sizeof(t_v3));
	d->col = cy->col;
	d->rad = cy->rad;
	mod->obj_nb++;
	mod->obj[mod->obj_nb].type = DSK;
	d = &(mod->obj[mod->obj_nb].dsk);
	ft_memcpy(d->pos, cy->pos, sizeof(t_v3));
	vec_move_along(d->pos, cy->ax, -cy->hgt);
	ft_memcpy(d->nor, cy->ax, sizeof(t_v3));
	d->col = cy->col;
	d->rad = cy->rad;
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
	model_add_cylinder_disk(mod, obj);
}

static void	model_add_cone_disk(t_model *mod, t_con *co)
{
	t_dsk	*d;

	mod->obj[mod->obj_nb].type = DSK;
	d = &(mod->obj[mod->obj_nb].dsk);
	ft_memcpy(d->pos, co->pos, sizeof(t_v3));
	vec_move_along(d->pos, co->ax, co->hgt);
	ft_memcpy(d->nor, co->ax, sizeof(t_v3));
	d->col = co->col;
	d->rad = tan(co->ang) * co->hgt;
	mod->obj_nb++;
	mod->obj[mod->obj_nb].type = DSK;
	d = &(mod->obj[mod->obj_nb].dsk);
	ft_memcpy(d->pos, co->pos, sizeof(t_v3));
	vec_move_along(d->pos, co->ax, -co->hgt);
	ft_memcpy(d->nor, co->ax, sizeof(t_v3));
	d->col = co->col;
	d->rad = tan(co->ang) * co->hgt;
	mod->obj_nb++;
}

void	model_add_cone(t_model *mod, t_cone *c)
{
	t_con	*obj;

	mod->obj[mod->obj_nb].type = CON;
	obj = &(mod->obj[mod->obj_nb].con);
	obj->pos[0] = c->pos.x;
	obj->pos[1] = c->pos.y;
	obj->pos[2] = c->pos.z;
	obj->ax[0] = c->axis.x;
	obj->ax[1] = c->axis.y;
	obj->ax[2] = c->axis.z;
	obj->ang = M_PI * c->angle / 180.f / 2;
	obj->hgt = c->height / 2;
	obj->col = (c->color.r << 16) | (c->color.g << 8) | c->color.b;
	mod->obj_nb++;
	model_add_cone_disk(mod, obj);
}

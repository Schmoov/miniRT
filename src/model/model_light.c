/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/05/14 13:37:28 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static t_rgb	object_color_at(t_obj *obj, t_v3 pos)
{
	if (obj->type == PLA)
		return (obj->pla.col);
	if (obj->type == SPH)
		return (obj->sph.col);
	if (obj->type == CYL)
		return (obj->cyl.col);
	__builtin_unreachable();
}

static void	object_normal_at(t_v3 res, t_model *m, t_impact *imp)
{
	t_obj *obj;

	obj = &(m->obj[imp->obj_idx]);
	if (obj->type == PLA)
		ft_memcpy(res, obj->pla.nor, sizeof(t_v3));
	if (obj->type == SPH)
	{
		ft_memcpy(res, imp->pos, sizeof(t_v3));
		vec_sub(res, res, obj->sph.pos);
		vec_normalize(res);
	}
	if (vec_dot(res, imp->ray.dir) > 0)
		vec_opp(res);
}


t_rgb	color_lit(t_model *m, t_impact *imp, t_v3 normal);
t_rgb	model_light(t_model *m, t_impact *imp)
{
	t_rgb	obj_col;
	t_rgb	amb_col;
	t_rgb	lit_col;
	t_v3	normal;

	obj_col = object_color_at(&(m->obj[imp->obj_idx]), imp->pos);
	amb_col = color_mult(m->amb, obj_col);
	object_normal_at(normal, m, imp);
	lit_col = color_lit(m, imp, normal);
	lit_col = color_mult(lit_col, obj_col);
	return (color_add(amb_col, lit_col));
}

t_rgb	color_lit(t_model *m, t_impact *imp, t_v3 normal)
{
	int			i;
	t_impact	bounce;
	t_rgb		res;
	t_v3		to_lit;

	ft_memcpy(bounce.ray.pos, imp->pos, sizeof(t_v3));
	i = 0;
	res = 0;
	while (i < m->lit_nb)
	{
		ft_memcpy(to_lit, m->lit[i].pos, sizeof(t_v3));
		vec_sub(to_lit, to_lit, imp->pos);
		ft_memcpy(bounce.ray.dir, to_lit, sizeof(t_v3));
		vec_normalize(bounce.ray.dir);
		if (vec_dot(normal, bounce.ray.dir) > 0)
		{
			model_impact(m, &bounce);
			if (bounce.scale > vec_norm(to_lit))
				res = color_add(res, color_scale(m->lit[i].col, vec_dot(normal, bounce.ray.dir)));
		}
		i++;
	}
	return res;
}

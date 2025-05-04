/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/05/04 14:40:30 by parden           ###   ########.fr       */
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

t_rgb	color_lit(t_model *m, t_impact *imp);
t_rgb	model_light(t_model *m, t_impact *imp)
{
	t_rgb	obj_col;
	t_rgb	amb_col;
	t_rgb	lit_col;

	obj_col = object_color_at(&(m->obj[imp->obj_idx]), imp->pos);
	amb_col = color_mult(m->amb, obj_col);
	lit_col = color_lit(m, imp);
	lit_col = color_mult(lit_col, obj_col);
	return (color_add(amb_col, lit_col));
}

t_rgb	color_lit(t_model *m, t_impact *imp)
{
	t_v3	n;

	object_normal_at(n, 
	//	get Normal
	//	For each lit
	//		Create ray
	//		if (!obstacle)
	//			color += reflect + shine;
	//	return color;
}

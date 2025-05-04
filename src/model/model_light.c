/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/05/04 14:19:53 by parden           ###   ########.fr       */
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

t_rgb	model_light(t_model *m, t_impact *imp)
{
	t_rgb	obj_col;
	t_rgb	amb_col;
	t_rgb	lit_col;

	obj_col = object_color_at(&(m->obj[imp->obj_idx]), imp->pos);
	amb_col = color_ambient(m, obj_col);
	lit_col = color_lit(m, imp, obj_col);
	return (color_add(amb_col, lit_col));
}

t_rgb	color_ambient(t_model *m, t_rgb obj_col)
{
	return (color_mult(m->amb, obj_col));
}

t_rgb	color_lit(t_model *m, t_impact *imp, t_rgb obj_col)
{
	//	get Normal
	//	For each lit
	//		Create ray
	//		if (!obstacle)
	//			color += reflect + shine;
	//	return color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/05/16 16:23:07 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"


t_rgb	model_light(t_model *m, t_impact *imp)
{
	t_rgb	amb_col;
	t_rgb	lit_col;

	amb_col = color_mult(m->amb, imp->col);
	lit_col = color_lit(m, imp);
	return (color_add(amb_col, lit_col));
}

t_rgb	color_lit(t_model *m, t_impact *imp)
{
	int			i;
	t_rgb		res;
	t_v3		to_lit;

	i = 0;
	res = 0;
	while (i < m->lit_nb)
	{
		res = color_add(res, color_one_lit(m, imp, &(m->lit[i])));
		i++;
	}
	return (res);
}

t_rgb	color_one_lit(t_model *m, t_impact *imp, t_lit *lit)
{
	t_impact	bounce;
	float		lit_dist;

	ft_memcpy(bounce.ray.pos, imp->pos, sizeof(t_v3));
	ft_memcpy(bounce.ray.dir, lit->pos, sizeof(t_v3));
	vec_sub(bounce.ray.dir, bounce.ray.dir, imp->pos);
	lit_dist = vec_norm(bounce.ray.dir);
	vec_normalize(bounce.ray.dir);
	if (vec_dot(imp->normal, bounce.ray.dir) <= 0)
		return (0);
	model_impact(m, &bounce);
	if (bounce.scale < lit_dist + EPS)
		return (0);

	t_rgb	lit_em = color_scale(lit->col, vec_dot(imp->normal, bounce.ray.dir));
	lit_em = color_mult(lit_em, imp->col);
	
	t_v3	refl;
	vec_rot_axis(refl, bounce.ray.dir, imp->normal);
	float	fact = pow(-vec_dot(refl, imp->ray.dir), 20);
	t_rgb	lit_spec = color_scale(lit->col, fact);
	return (color_add(lit_em, lit_spec));
}

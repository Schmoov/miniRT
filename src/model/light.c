/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/06/20 14:29:23 by parden           ###   ########.fr       */
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

	i = 0;
	res = 0;
	while (i < m->lit_nb)
	{
		res = color_add(res, color_one_lit(m, imp, &(m->lit[i])));
		i++;
	}
	return (res);
}

bool	color_bounce(t_model *m, t_impact *imp, t_lit *lit, t_impact *bounce)
{
	float		lit_dist;

	ft_memcpy(bounce->ray.pos, imp->pos, sizeof(t_v3));
	ft_memcpy(bounce->ray.dir, lit->pos, sizeof(t_v3));
	vec_sub(bounce->ray.dir, bounce->ray.dir, imp->pos);
	lit_dist = vec_norm(bounce->ray.dir);
	vec_normalize(bounce->ray.dir);
	if (vec_dot(imp->normal, bounce->ray.dir) < EPS_TGT)
		return (false);
	model_impact(m, bounce);
	if (bounce->scale < lit_dist + EPS_ACNE)
		return (false);
	return (true);
}

t_rgb	color_one_lit(t_model *m, t_impact *imp, t_lit *lit)
{
	t_impact	bounce;
	t_rgb		lit_em;
	t_rgb		lit_spec;
	t_v3		refl;

	if (!color_bounce(m, imp, lit, &bounce))
		return (0);
	lit_em = color_scale(lit->col, vec_dot(imp->normal, bounce.ray.dir));
	lit_em = color_mult(lit_em, imp->col);
	vec_rot_axis(refl, bounce.ray.dir, imp->normal);
	lit_spec = color_scale(lit->col, pow(-vec_dot(refl, imp->ray.dir), 20));
	return (color_add(lit_em, lit_spec));
}

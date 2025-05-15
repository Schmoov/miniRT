/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/05/15 17:14:52 by parden           ###   ########.fr       */
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

t_rgb	color_one_lit(t_model *m, t_impact *imp, t_lit *lit);
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
	return res;
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
	return (color_scale(lit->col, vec_dot(imp->normal, bounce.ray.dir)));
}

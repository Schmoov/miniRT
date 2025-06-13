/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact_object1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:12:04 by parden            #+#    #+#             */
/*   Updated: 2025/06/13 14:58:18 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	impact_plane(t_model *m, t_impact *imp, t_pla *pla)
{
	float	scale;
	t_v3	v_rp;

	if (fabsf(vec_dot(imp->ray.dir, pla->nor)) < EPS_TGT)
		return ;
	vec_sub(v_rp, pla->pos, imp->ray.pos);
	scale = vec_dot(v_rp, pla->nor)
		/ vec_dot(imp->ray.dir, pla->nor);
	if (scale > EPS_ACNE && scale < imp->scale)
		imp->scale = scale;
}

void	impact_disk(t_model *m, t_impact *imp, t_dsk *dsk)
{
	float	scale;
	t_v3	v_rp;

	if (fabsf(vec_dot(imp->ray.dir, dsk->nor)) < EPS_TGT)
		return ;
	vec_sub(v_rp, dsk->pos, imp->ray.pos);
	scale = vec_dot(v_rp, dsk->nor)
		/ vec_dot(imp->ray.dir, dsk->nor);
	ft_memcpy(v_rp, imp->ray.pos, sizeof(t_v3));
	vec_move_along(v_rp, imp->ray.dir, scale);
	vec_sub(v_rp, v_rp, dsk->pos);
	if (scale > EPS_ACNE && scale < imp->scale && vec_norm(v_rp) < dsk->rad)
		imp->scale = scale;
}

void	impact_sphere(t_model *m, t_impact *imp, t_sph *sph)
{
	t_v3		v_cr;
	t_eq_quad	eq;

	vec_sub(v_cr, imp->ray.pos, sph->pos);
	eq.a = 1.0f;
	eq.b = 2 * vec_dot(imp->ray.dir, v_cr);
	eq.c = vec_norm2(v_cr) - powf(sph->rad, 2);
	eq_quad_solve(&eq);
	if (!eq.has_solution)
		return ;
	if (eq.x2 > EPS_ACNE && eq.x2 < eq.x1)
		eq.x1 = eq.x2;
	if (eq.x1 > EPS_ACNE && eq.x1 < imp->scale)
		imp->scale = eq.x1;
}

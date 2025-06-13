/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact_object2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:12:04 by parden            #+#    #+#             */
/*   Updated: 2025/06/13 16:15:51 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static void	eq_cyl_init(t_eq_quad *eq, t_impact *imp, t_cyl *cyl)
{
	t_v3		v_rc;
	t_v3		tmp1;
	t_v3		tmp2;

	vec_sub(v_rc, imp->ray.pos, cyl->pos);
	vec_cross(tmp1, cyl->ax, imp->ray.dir);
	vec_cross(tmp2, cyl->ax, v_rc);
	eq->a = vec_norm2(tmp1);
	eq->b = 2 * vec_dot(tmp1, tmp2);
	eq->c = vec_norm2(tmp2) - cyl->rad * cyl->rad;
}

static float	height_cyl_impact(t_impact *imp, t_cyl *cyl, float scale)
{
	t_v3	tmp;

	ft_memcpy(tmp, imp->ray.pos, sizeof(t_v3));
	vec_move_along(tmp, imp->ray.dir, scale);
	vec_sub(tmp, tmp, cyl->pos);
	return (fabs(vec_dot(tmp, cyl->ax)));
}

void	impact_cylinder(t_model *m, t_impact *imp, t_cyl *cyl)
{
	t_eq_quad	eq;
	float		h1;
	float		h2;

	eq_cyl_init(&eq, imp, cyl);
	eq_quad_solve(&eq);
	if (!eq.has_solution)
		return ;
	h1 = height_cyl_impact(imp, cyl, eq.x1);
	h2 = height_cyl_impact(imp, cyl, eq.x2);
	if (eq.x2 > EPS_ACNE && eq.x2 < eq.x1 && h2 < cyl->hgt)
	{
		eq.x1 = eq.x2;
		h1 = h2;
	}
	if (eq.x1 > EPS_ACNE && eq.x1 < imp->scale && h1 < cyl->hgt)
		imp->scale = eq.x1;
}

static float	height_con_impact(t_impact *imp, t_con *con, float scale)
{
	t_v3	tmp;

	ft_memcpy(tmp, imp->ray.pos, sizeof(t_v3));
	vec_move_along(tmp, imp->ray.dir, scale);
	vec_sub(tmp, tmp, con->pos);
	return (fabs(vec_dot(tmp, con->ax)));
}

void	impact_cone(t_model *m, t_impact *imp, t_con *con)
{
	t_eq_quad	eq;
	t_v3		v_rc;
	float		h1;
	float		h2;

	vec_sub(v_rc, imp->ray.pos, con->pos);
	eq.a = pow(vec_dot(imp->ray.dir, con->ax), 2) - pow(cos(con->ang), 2);
	eq.b = 2 * (vec_dot(imp->ray.dir, con->ax) * vec_dot(v_rc, con->ax)
			- (vec_dot(imp->ray.dir, v_rc) * pow(cos(con->ang), 2)));
	eq.c = pow(vec_dot(v_rc, con->ax), 2)
		- vec_norm2(v_rc) * pow(cos(con->ang), 2);
	eq_quad_solve(&eq);
	if (!eq.has_solution)
		return ;
	h1 = height_con_impact(imp, con, eq.x1);
	h2 = height_con_impact(imp, con, eq.x2);
	if (eq.x2 > EPS_ACNE && eq.x2 < eq.x1 && h2 < con->hgt)
	{
		eq.x1 = eq.x2;
		h1 = h2;
	}
	if (eq.x1 > EPS_ACNE && eq.x1 < imp->scale && h1 < con->hgt)
		imp->scale = eq.x1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impact_object2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:12:04 by parden            #+#    #+#             */
/*   Updated: 2025/06/13 13:25:27 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	impact_cylinder(t_model *m, t_impact *imp, t_cyl *cyl)
{
	t_v3	v_rc;
	vec_sub(v_rc, imp->ray.pos, cyl->pos);
	t_v3	tmp1;
	vec_cross(tmp1, cyl->ax, v_rc);
	t_v3	tmp2;
	vec_cross(tmp2, cyl->ax, imp->ray.dir);
	float a = vec_norm2(tmp2);
	float b = 2 * vec_dot(tmp1, tmp2);
	float c = vec_norm2(tmp1) -cyl->rad * cyl->rad;
	float delta = b*b - 4*a*c;
	if (delta < EPS)
		return;
	float x1 = (-b + sqrt(delta)) / (2 * a);
	float x2 = (-b - sqrt(delta)) / (2 * a);

	t_v3 vx1;
	ft_memcpy(vx1, imp->ray.pos, sizeof(t_v3));
	vec_move_along(vx1, imp->ray.dir, x1);
	vec_sub(vx1, vx1, cyl->pos);
	float h1 = fabs(vec_dot(vx1, cyl->ax));
	t_v3 vx2;
	ft_memcpy(vx2, imp->ray.pos, sizeof(t_v3));
	vec_move_along(vx2, imp->ray.dir, x2);
	vec_sub(vx2, vx2, cyl->pos);
	float h2 = fabs(vec_dot(vx2, cyl->ax));

	if (x2 > EPS && x2 < x1 && h2 < cyl->hgt) {
		x1 = x2;
		h1 = h2;
	}
	if (x1 > EPS && x1 < imp->scale && h1 < cyl->hgt)
		imp->scale = x1;
}

void	impact_cone(t_model *m, t_impact *imp, t_con *con)
{
	t_v3	v_rc;
	vec_sub(v_rc, imp->ray.pos, con->pos);
	float a = pow(vec_dot(imp->ray.dir, con->ax), 2);
	a -= pow(cos(con->ang), 2);
	float b = 2 * (vec_dot(imp->ray.dir, con->ax) * vec_dot(v_rc, con->ax)
			- (vec_dot(imp->ray.dir, v_rc) * pow(cos(con->ang), 2)));
	float c = pow(vec_dot(v_rc, con->ax), 2)
			- vec_norm2(v_rc) * pow(cos(con->ang), 2);
	float delta = b*b - 4*a*c;
	if (delta < EPS)
		return;
	float x1 = (-b + sqrt(delta)) / (2 * a);
	float x2 = (-b - sqrt(delta)) / (2 * a);

	t_v3 vx1;
	ft_memcpy(vx1, imp->ray.pos, sizeof(t_v3));
	vec_move_along(vx1, imp->ray.dir, x1);
	vec_sub(vx1, vx1, con->pos);
	float h1 = fabs(vec_dot(vx1, con->ax));
	t_v3 vx2;
	ft_memcpy(vx2, imp->ray.pos, sizeof(t_v3));
	vec_move_along(vx2, imp->ray.dir, x2);
	vec_sub(vx2, vx2, con->pos);
	float h2 = fabs(vec_dot(vx2, con->ax));

	if (x2 > EPS && x2 < x1 && h2 < con->hgt) {
		x1 = x2;
		h1 = h2;
	}
	if (x1 > EPS && x1 < imp->scale && h1 < con->hgt)
		imp->scale = x1;
}

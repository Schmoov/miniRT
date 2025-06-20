/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:45:30 by parden            #+#    #+#             */
/*   Updated: 2025/06/20 14:34:10 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	bump_pla(t_model *m, t_impact *imp, t_pla *obj)
{
	t_v3	vec;
	int		fx;
	int		fy;
	float	dx;
	float	dy;

	(void) m;
	if (!obj->bump.buf)
		return ;
	vec_sub(vec, imp->pos, obj->pos);
	fx = (((int)vec_dot(obj->e3, vec)) % obj->bump.w) + obj->bump.w;
	fx %= obj->bump.w;
	fy = ((int)vec_dot(obj->e2, vec)) % obj->bump.h;
	fy += obj->bump.h;
	fy %= obj->bump.h;
	dx = obj->bump.buf[fy * obj->bump.w + ((fx + 1) % obj->bump.w)]
		- (int)obj->bump.buf[fy * obj->bump.w + fx];
	dy = obj->bump.buf[((fy + 1) % obj->bump.h) * obj->bump.w + fx]
		- (int)obj->bump.buf[fy * obj->bump.w + fx];
	dx /= BUMP_FACTOR;
	dy /= BUMP_FACTOR;
	imp->normal[0] += dx * obj->e3[0] + dy * obj->e2[0];
	imp->normal[1] += dx * obj->e3[1] + dy * obj->e2[1];
	imp->normal[2] += dx * obj->e3[2] + dy * obj->e2[2];
	vec_normalize(imp->normal);
}

void	bump_sph_helper(t_sph *obj, t_v3 vec, float *dx, float *dy)
{
	int	fx;
	int	fy;

	fx = roundf(obj->bump.w * acosf(vec[1]) / (2 * M_PI));
	fy = roundf(obj->bump.h * atan2f(vec[2], vec[0]) / (2 * M_PI));
	fx += obj->bump.w;
	fx %= obj->bump.w;
	fy += obj->bump.h;
	fy %= obj->bump.h;
	*dx = obj->bump.buf[fy * obj->bump.w + ((fx + 1) % obj->bump.w)]
		- (int)obj->bump.buf[fy * obj->bump.w + fx];
	*dy = obj->bump.buf[((fy + 1) % obj->bump.h) * obj->bump.w + fx]
		- (int)obj->bump.buf[fy * obj->bump.w + fx];
	*dx /= BUMP_FACTOR;
	*dy /= BUMP_FACTOR;
}

void	bump_sph(t_model *m, t_impact *imp, t_sph *obj)
{
	t_v3	vec;
	t_v3	vt;
	t_v3	vb;
	float	dx;
	float	dy;

	(void) m;
	if (!obj->bump.buf)
		return ;
	vec_sub(vec, imp->pos, obj->pos);
	vec_normalize(vec);
	vec_cross(vt, (t_v3){0, -1, 0}, vec);
	vec_normalize(vt);
	vec_cross(vb, vec, vt);
	vec_normalize(vb);
	bump_sph_helper(obj, vec, &dx, &dy);
	imp->normal[0] += dx * vb[0] + dy * vt[0];
	imp->normal[1] += dx * vb[1] + dy * vt[1];
	imp->normal[2] += dx * vb[2] + dy * vt[2];
	vec_normalize(imp->normal);
}

void	bump_normal(t_model *m, t_impact *imp, t_obj *obj)
{
	if (obj->type == PLA)
		bump_pla(m, imp, &obj->pla);
	if (obj->type == SPH)
		bump_sph(m, imp, &obj->sph);
	if (obj->type == CYL)
		bump_cyl(m, imp, &obj->cyl);
	if (obj->type == CON)
		bump_con(m, imp, &obj->con);
}

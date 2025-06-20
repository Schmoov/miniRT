/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:45:30 by parden            #+#    #+#             */
/*   Updated: 2025/06/20 14:31:10 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	bump_cyl_helper(t_cyl *obj, t_v3 vec, float *dx, float *dy)
{
	float	u;
	int		fx;
	int		fy;
	t_v3	radial;

	vec_scale(radial, obj->ax, vec_dot(vec, obj->ax));
	vec_sub(radial, vec, radial);
	vec_normalize(radial);
	u = atan2f(vec_dot(radial, obj->e2), vec_dot(radial, obj->e3));
	fx = (int)(u / (2 * M_PI) * obj->bump.w) % obj->bump.w;
	fy = (int)(vec_dot(vec, obj->ax) / obj->hgt * obj->bump.h) % obj->bump.h;
	fx = (fx + obj->bump.w) % obj->bump.w;
	fy = (fy + obj->bump.h) % obj->bump.h;
	*dx = obj->bump.buf[fy * obj->bump.w + ((fx + 1) % obj->bump.w)]
		- (int)obj->bump.buf[fy * obj->bump.w + fx];
	*dy = obj->bump.buf[((fy + 1) % obj->bump.h) * obj->bump.w + fx]
		- (int)obj->bump.buf[fy * obj->bump.w + fx];
}

void	bump_cyl(t_model *m, t_impact *imp, t_cyl *obj)
{
	t_v3	vec;
	float	dx;
	float	dy;

	(void) m;
	if (!obj->bump.buf)
		return ;
	vec_sub(vec, imp->pos, obj->pos);
	bump_cyl_helper(obj, vec, &dx, &dy);
	dx /= BUMP_FACTOR;
	dy /= BUMP_FACTOR;
	imp->normal[0] += dx * obj->e3[0] + dy * obj->ax[0];
	imp->normal[1] += dx * obj->e3[1] + dy * obj->ax[1];
	imp->normal[2] += dx * obj->e3[2] + dy * obj->ax[2];
	vec_normalize(imp->normal);
}

void	bump_con_helper(t_con *obj, t_v3 vec, float *dx, float *dy)
{
	float	u;
	int		fx;
	int		fy;
	t_v3	radial;

	vec_scale(radial, obj->ax, vec_dot(vec, obj->ax));
	vec_sub(radial, vec, radial);
	vec_normalize(radial);
	u = atan2f(vec_dot(radial, obj->e2), vec_dot(radial, obj->e3));
	fx = (int)(u / (2 * M_PI) * obj->bump.w) % obj->bump.w;
	fy = (int)(vec_dot(vec, obj->ax) / obj->hgt * obj->bump.h) % obj->bump.h;
	fx = (fx + obj->bump.w) % obj->bump.w;
	fy = (fy + obj->bump.h) % obj->bump.h;
	*dx = obj->bump.buf[fy * obj->bump.w + ((fx + 1) % obj->bump.w)]
		- (int)obj->bump.buf[fy * obj->bump.w + fx];
	*dy = obj->bump.buf[((fy + 1) % obj->bump.h) * obj->bump.w + fx]
		- (int)obj->bump.buf[fy * obj->bump.w + fx];
}

void	bump_con(t_model *m, t_impact *imp, t_con *obj)
{
	t_v3	vec;
	float	dx;
	float	dy;

	(void) m;
	if (!obj->bump.buf)
		return ;
	vec_sub(vec, imp->pos, obj->pos);
	bump_con_helper(obj, vec, &dx, &dy);
	dx /= BUMP_FACTOR;
	dy /= BUMP_FACTOR;
	imp->normal[0] += dx * obj->e3[0] + dy * obj->ax[0];
	imp->normal[1] += dx * obj->e3[1] + dy * obj->ax[1];
	imp->normal[2] += dx * obj->e3[2] + dy * obj->ax[2];
	vec_normalize(imp->normal);
}

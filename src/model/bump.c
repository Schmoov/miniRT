/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:45:30 by parden            #+#    #+#             */
/*   Updated: 2025/06/18 14:58:54 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	bump_pla(t_model *m, t_impact *imp, t_pla *obj)
{
	t_v3	vec;
	int		fx;
	int		fy;
	int		dx;
	int		dy;

	if (!obj->bump.buf)
		return ;
	vec_sub(vec, imp->pos, obj->pos);
	fx = ((int)vec_dot(obj->e3, vec)) % obj->bump.w;
	fx += obj->bump.w;
	fx %= obj->bump.w;
	fy = ((int)vec_dot(obj->e2, vec)) % obj->bump.h;
	fy += obj->bump.h;
	fy %= obj->bump.h;


	dx = obj->bump.buf[fy * obj->bump.w + ((fx + 1) % obj->bump.w)] - (int)obj->bump.buf[fy * obj->bump.w + fx];
	dy = obj->bump.buf[((fy + 1) % obj->bump.h) * obj->bump.w + fx] - (int)obj->bump.buf[fy * obj->bump.w + fx];
	float px = dx / BUMP_FACTOR;
	float py = dy / BUMP_FACTOR;
	imp->normal[0] += px * obj->e3[0] + py * obj->e2[0];
	imp->normal[1] += px * obj->e3[1] + py * obj->e2[1];
	imp->normal[2] += px * obj->e3[2] + py * obj->e2[2];
	vec_normalize(imp->normal);

}

void	bump_sph(t_model *m, t_impact *imp, t_sph *obj)
{
}

void	bump_cyl(t_model *m, t_impact *imp, t_cyl *obj)
{
}

void	bump_con(t_model *m, t_impact *imp, t_con *obj)
{
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

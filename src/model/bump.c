/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:45:30 by parden            #+#    #+#             */
/*   Updated: 2025/06/16 19:38:01 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include <stdio.h>

void	bump_pla(t_model *m, t_impact *imp, t_pla *obj)
{
	t_v3	vec;
	int		f2;
	int		f3;
	int		d2;
	int		d3;

	if (!obj->bump.buf)
		return ;
	vec_sub(vec, imp->pos, obj->pos);
	f2 = ((int)vec_dot(obj->e2, vec)) % obj->bump.w;
	f2 += obj->bump.w;
	f2 %= obj->bump.w;
	f3 = ((int)vec_dot(obj->e3, vec)) % obj->bump.h;
	f3 += obj->bump.h;
	f3 %= obj->bump.h;

	/*
	printf("%d %d\n", f2, f3);
	printf("%d\n", obj->bump->data[f2][f3]);
	return;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d ", (int)obj->bump->data[i][j]);
		}
		printf("\n");
	}
	fflush(stdout);
	*/

	d2 = obj->bump.buf[((f2 + 1) % obj->bump.h) * obj->bump.w + f3] - (int)obj->bump.buf[f2 * obj->bump.w + f3];
	d3 = obj->bump.buf[f2 * obj->bump.w + ((f3 + 1) % obj->bump.h)] - (int)obj->bump.buf[f2 * obj->bump.w + f3];
	float p2 = d2 / 1000.f;
	float p3 = d3 / 1000.f;
	imp->normal[0] += p2 * obj->e2[0] + p3 * obj->e3[0];
	imp->normal[1] += p2 * obj->e2[1] + p3 * obj->e3[1];
	imp->normal[2] += p2 * obj->e2[2] + p3 * obj->e3[2];
	vec_normalize(imp->normal);
	//printf("%f %f %f\n", imp->normal[0],imp->normal[1],imp->normal[2]);

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

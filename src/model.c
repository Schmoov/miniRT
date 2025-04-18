/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/04/18 19:58:14 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/model.h"

t_rgb	*model_compute(t_model *m)
{
	t_rgb	*res;
	int		x;
	int		y;

	res = ft_calloc(W * H, sizeof(t_rgb));
	if (!res)
		return (model_destroy(m), NULL);
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			res[y * W + x] = model_pixel(m, x, y);
			x++;
		}
		y++;
	}
	return (res);
}

void	model_pixel_camray(t_model *m, t_ray *r, int x, int y)
{
	ft_memcpy(r->pos, m->cam.pos, sizeof(t_v3));
	ft_memcpy(r->dir, m->cam.pos_scr, sizeof(t_v3));
	vec_move_along(r->dir, m->cam.vx_scr, x / (float)(W - 1));
	vec_move_along(r->dir, m->cam.vy_scr, y / (float)(H - 1));
	vec_sub(r->dir, r->dir, m->cam.pos);
	vec_normalize(r->dir);
}

t_rgb	model_pixel(t_model *m, int x, int y)
{
	t_impact	imp;

	model_pixel_camray(m, &imp.ray, x, y);
	model_pixel_impact(m, &imp);
	return (model_light(m, &imp));
}

void	model_pixel_impact(t_model *m, t_impact *imp)
{
	int	i;

	imp->scale = INF;
	i = 0;
	while (i < m->obj_nb)
	{
		model_impact_object(m, imp, i);
		i++;
	}
}

static t_rgb	model_obj_color(t_obj *obj)
{
	if (obj->type == PLA)
		return (obj->pla.col);
	if (obj->type == SPH)
		return (obj->sph.col);
	if (obj->type == CYL)
		return (obj->cyl.col);
	__builtin_unreachable();
}

t_rgb	model_light(t_model *m, t_impact *imp)
{
	t_rgb	res;
	t_rgb	obj_col;

	obj_col = model_obj_color(&(m->obj[imp->obj_idx]));
	res = 0;
	res |= RED & ((int)roundf(m->amb.lum
		* ((RED & m->amb.col) >> 16) * ((RED & obj_col) >> 16))
		<< 16);
	res |= GRN & ((int)roundf(m->amb.lum
		* ((GRN & m->amb.col) >> 8) * ((GRN & obj_col) >> 8))
		<< 8);
	res |= BLU & (int)roundf(m->amb.lum
		* (BLU & m->amb.col) * (BLU & obj_col));
	return (res);
}


	


/*
// inter(ray, mod) {
// float best = -1;
// Point res;
// 		for (obj in mod->obj)
// 			if (inter_obj(obj, ray) < best)
// 				best = inter
//
// 		return best;
// }
*/

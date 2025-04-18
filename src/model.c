/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/04/18 18:05:30 by parden           ###   ########.fr       */
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
	t_ray		r;
	t_impact	imp;

	model_pixel_camray(m, &r, x, y);
	model_pixel_impact(m, &imp, &r);
	return (model_light(m, &imp));
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/06/18 16:14:09 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

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
	model_destroy(m);
	return (res);
}

void	model_pixel_camray(t_model *m, t_ray *r, int x, int y)
{
	ft_memcpy(r->pos, m->cam.pos, sizeof(t_v3));
	ft_memcpy(r->dir, m->cam.pos_scr, sizeof(t_v3));
	vec_move_along(r->dir, m->cam.vx_scr, m->cam.w_scr * x / (float)(W - 1));
	vec_move_along(r->dir, m->cam.vy_scr, m->cam.h_scr * y / (float)(H - 1));
	vec_sub(r->dir, r->dir, m->cam.pos);
	vec_normalize(r->dir);
}

t_rgb	model_pixel(t_model *m, int x, int y)
{
	t_impact	imp;

	ft_memset(&imp, 0, sizeof(imp));
	model_pixel_camray(m, &imp.ray, x, y);
	model_impact(m, &imp);
	return (model_light(m, &imp));
}

void	model_impact(t_model *m, t_impact *imp)
{
	int		i;
	float	old_scale;

	imp->scale = INF;
	i = 0;
	while (i < m->obj_nb)
	{
		old_scale = imp->scale;
		model_impact_object(m, imp, i);
		if (imp->scale < old_scale)
		{
			imp->obj_idx = i;
			imp->pos[0] = imp->scale * imp->ray.dir[0] + imp->ray.pos[0];
			imp->pos[1] = imp->scale * imp->ray.dir[1] + imp->ray.pos[1];
			imp->pos[2] = imp->scale * imp->ray.dir[2] + imp->ray.pos[2];
			impact_normal(m, imp);
			impact_color(m, imp);
		}
		i++;
	}
}

void	model_impact_object(t_model *m, t_impact *imp, int i)
{
	t_obj	*obj;

	obj = &(m->obj[i]);
	if (obj->type == PLA)
		impact_plane(m, imp, &(obj->pla));
	if (obj->type == SPH)
		impact_sphere(m, imp, &(obj->sph));
	if (obj->type == DSK)
		impact_disk(m, imp, &(obj->dsk));
	if (obj->type == CYL)
		impact_cylinder(m, imp, &(obj->cyl));
	if (obj->type == CON)
		impact_cone(m, imp, &(obj->con));
}

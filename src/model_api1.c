/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_api1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:20:19 by parden            #+#    #+#             */
/*   Updated: 2025/04/18 17:21:42 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/model.h"

bool	model_init(t_model *mod)
{
	ft_memset(mod, 0, sizeof(t_model));
	return (true);
}

void	model_destroy(t_model *mod)
{
}

static void	model_set_cam_axis(t_cam *c)
{
	if (c->dir[0] <= c->dir[1] && c->dir[0] <= c->dir[2])
		vec_cross(c->y_scr, c->dir, (t_v3){1, 0, 0});
	else if (c->dir[1] <= c->dir[2])
		vec_cross(c->y_scr, c->dir, (t_v3){0, 1, 0});
	else
		vec_cross(c->y_scr, c->dir, (t_v3){0, 0, 1});
	vec_norm(c->y_scr);
	vec_cross(c->x_scr, c->y_scr, c->dir);
}

void	model_set_cam(t_model *mod, t_camera *cam)
{
	mod->cam.pos[0] = cam->pos.x;
	mod->cam.pos[1] = cam->pos.y;
	mod->cam.pos[2] = cam->pos.z;
	mod->cam.dir[0] = cam->orientation.x;
	mod->cam.dir[1] = cam->orientation.y;
	mod->cam.dir[2] = cam->orientation.z;
	mod->cam.fov = cam->fov;
	model_set_cam_axis(&mod->cam);
}

void	model_set_ambient(t_model *mod, t_ambient_lighting *amb)
{
	mod->amb.lum = amb->ratio;
	mod->amb.col = (amb->color.r << 8) | (amb->color.g << 4) | amb->color.b;
}

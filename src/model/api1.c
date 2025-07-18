/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:20:19 by parden            #+#    #+#             */
/*   Updated: 2025/06/20 13:34:09 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

bool	model_init(t_model *mod)
{
	ft_memset(mod, 0, sizeof(t_model));
	return (true);
}

void	model_destroy(t_model *mod)
{
	int	i;

	i = 0;
	while (i < mod->obj_nb)
	{
		if (mod->obj[i].type == PLA)
			free(mod->obj[i].pla.bump.buf);
		if (mod->obj[i].type == CYL)
			free(mod->obj[i].cyl.bump.buf);
		if (mod->obj[i].type == SPH)
			free(mod->obj[i].sph.bump.buf);
		if (mod->obj[i].type == CON)
			free(mod->obj[i].con.bump.buf);
		i++;
	}
}

void	model_set_cam(t_model *mod, t_camera *cam)
{
	mod->cam.pos[0] = cam->pos.x;
	mod->cam.pos[1] = cam->pos.y;
	mod->cam.pos[2] = cam->pos.z;
	mod->cam.dir[0] = cam->orientation.x;
	mod->cam.dir[1] = cam->orientation.y;
	mod->cam.dir[2] = cam->orientation.z;
	mod->cam.fov = M_PI * cam->fov / 180.f;
	model_set_cam_screen(&mod->cam);
}

void	model_set_ambient(t_model *mod, t_ambient_lighting *amb)
{
	mod->amb = (amb->color.r << 16) | (amb->color.g << 8) | amb->color.b;
	mod->amb = color_scale(mod->amb, amb->ratio);
}

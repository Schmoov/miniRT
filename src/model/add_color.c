/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:24:49 by parden            #+#    #+#             */
/*   Updated: 2025/06/14 19:04:49 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	model_add_plane_color(t_plane *p, t_pla *obj)
{
	obj->col1 = (p->color.r << 16) | (p->color.g << 8) | p->color.b;
	obj->check = false;
	if (p->damier)
	{
		obj->check = true;
		obj->col2 = (p->damier->color2.r << 16)
			| (p->damier->color2.g << 8) | p->damier->color2.b;
	}
}

void	model_add_sphere_color(t_sphere *p, t_sph *obj)
{
	obj->col1 = (p->color.r << 16) | (p->color.g << 8) | p->color.b;
	obj->check = false;
	if (p->damier)
	{
		obj->check = true;
		obj->col2 = (p->damier->color2.r << 16)
			| (p->damier->color2.g << 8) | p->damier->color2.b;
	}
}

void	model_add_cyl_disk_color(t_cyl *c, t_dsk *obj)
{
	obj->col1 = c->col1;
	obj->check = c->check;
	if (obj->check)
		obj->col2 = c->col2;
}

void	model_add_cyl_color(t_cylinder *p, t_cyl *obj)
{
	obj->col1 = (p->color.r << 16) | (p->color.g << 8) | p->color.b;
	obj->check = false;
	if (p->damier)
	{
		obj->check = true;
		obj->col2 = (p->damier->color2.r << 16)
			| (p->damier->color2.g << 8) | p->damier->color2.b;
	}
}

void	model_add_con_disk_color(t_con *c, t_dsk *obj)
{
	obj->col1 = c->col1;
	obj->check = c->check;
	if (obj->check)
		obj->col2 = c->col2;
}

void	model_add_con_color(t_cone *p, t_con *obj)
{
	obj->col1 = (p->color.r << 16) | (p->color.g << 8) | p->color.b;
	obj->check = false;
	if (p->damier)
	{
		obj->check = true;
		obj->col2 = (p->damier->color2.r << 16)
			| (p->damier->color2.g << 8) | p->damier->color2.b;
	}
}

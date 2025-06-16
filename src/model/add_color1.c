/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:24:49 by parden            #+#    #+#             */
/*   Updated: 2025/06/16 17:15:23 by parden           ###   ########.fr       */
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

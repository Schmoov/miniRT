/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:23:40 by parden            #+#    #+#             */
/*   Updated: 2025/04/24 15:34:50 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static void	model_screen_axis(t_cam *c)
{
	if (c->dir[0] <= c->dir[1] && c->dir[0] <= c->dir[2])
		vec_cross(c->vy_scr, (t_v3){1, 0, 0}, c->dir);
	else if (c->dir[1] <= c->dir[2])
		vec_cross(c->vy_scr, (t_v3){0, 1, 0}, c->dir);
	else
		vec_cross(c->vy_scr, (t_v3){0, 0, 1}, c->dir);
	vec_norm(c->vy_scr);
	vec_cross(c->vx_scr, c->vy_scr, c->dir);
}

static void	model_screen_pos(t_cam *c)
{
	c->w_scr = 2 * tan(c->fov / 2);
	c->h_scr = H * c->w_scr / W;
	ft_memcpy(c->pos_scr, c->pos, sizeof(t_v3));
	vec_move_along(c->pos_scr, c->dir, 1.0);
	vec_move_along(c->pos_scr, c->vx_scr, -.5 * c->w_scr);
	vec_move_along(c->pos_scr, c->vy_scr, -.5 * c->h_scr);
}

void	model_set_cam_screen(t_cam *c)
{
	model_screen_axis(c);
	model_screen_pos(c);
}

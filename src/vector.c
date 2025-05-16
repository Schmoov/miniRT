/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:47:33 by parden            #+#    #+#             */
/*   Updated: 2025/05/16 17:41:20 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/model.h"

float	vec_norm(t_v3 v)
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}

float	vec_norm2(t_v3 v)
{
	return (v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

void	vec_normalize(t_v3 v)
{
	float	n;

	n = vec_norm(v);
	v[0] /= n;
	v[1] /= n;
	v[2] /= n;
}

void	vec_opp(t_v3 v)
{
	v[0] = -v[0];
	v[1] = -v[1];
	v[2] = -v[2];
}

void	vec_scale(t_v3 res, t_v3 dir, float scale)
{
	res[0] = scale * dir[0];
	res[1] = scale * dir[1];
	res[2] = scale * dir[2];
}

void	vec_move_along(t_v3 point, t_v3 dir, float scale)
{
	point[0] += scale * dir[0];
	point[1] += scale * dir[1];
	point[2] += scale * dir[2];
}

void	vec_sub(t_v3 res, t_v3 v1, t_v3 v2)
{
	res[0] = v1[0] - v2[0];
	res[1] = v1[1] - v2[1];
	res[2] = v1[2] - v2[2];
}

float	vec_dot(t_v3 v1, t_v3 v2)
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

void	vec_cross(t_v3 res, t_v3 v1, t_v3 v2)
{
	res[0] = v1[1] * v2[2] - v1[2] * v2[1];
	res[1] = v1[0] * v2[2] - v1[2] * v2[0];
	res[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void	vec_rot_axis(t_v3 res, t_v3 v, t_v3 ax)
{
	float	fac;

	ft_memcpy(res, v, sizeof(t_v3));
	vec_opp(res);
	fac = 2 * vec_dot(ax, v);
	res[0] = res[0] + fac * ax[0];
	res[1] = res[1] + fac * ax[1];
	res[2] = res[2] + fac * ax[2];
}

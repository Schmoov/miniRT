/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:47:33 by parden            #+#    #+#             */
/*   Updated: 2025/06/13 15:05:17 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/model.h"

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

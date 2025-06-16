/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:48:43 by parden            #+#    #+#             */
/*   Updated: 2025/06/16 16:40:55 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	add_plane_axis(t_pla *p)
{
	if (fabs(p->nor[0]) <= fabs(p->nor[1])
		&& fabs(p->nor[0]) <= fabs(p->nor[2]))
		vec_cross(p->e2, (t_v3){1, 0, 0}, p->nor);
	else if (fabs(p->nor[1]) <= fabs(p->nor[2]))
		vec_cross(p->e2, (t_v3){0, 1, 0}, p->nor);
	else
		vec_cross(p->e2, (t_v3){0, 0, 1}, p->nor);
	vec_normalize(p->e2);
	vec_cross(p->e3, p->e2, p->nor);
}

void	add_disk_axis(t_dsk *p)
{
	if (fabs(p->nor[0]) <= fabs(p->nor[1])
		&& fabs(p->nor[0]) <= fabs(p->nor[2]))
		vec_cross(p->e2, (t_v3){1, 0, 0}, p->nor);
	else if (fabs(p->nor[1]) <= fabs(p->nor[2]))
		vec_cross(p->e2, (t_v3){0, 1, 0}, p->nor);
	else
		vec_cross(p->e2, (t_v3){0, 0, 1}, p->nor);
	vec_normalize(p->e2);
	vec_cross(p->e3, p->e2, p->nor);
}

void	add_cyl_axis(t_cyl *p)
{
	if (fabs(p->ax[0]) <= fabs(p->ax[1]) && fabs(p->ax[0]) <= fabs(p->ax[2]))
		vec_cross(p->e2, (t_v3){1, 0, 0}, p->ax);
	else if (fabs(p->ax[1]) <= fabs(p->ax[2]))
		vec_cross(p->e2, (t_v3){0, 1, 0}, p->ax);
	else
		vec_cross(p->e2, (t_v3){0, 0, 1}, p->ax);
	vec_normalize(p->e2);
	vec_cross(p->e3, p->e2, p->ax);
	printf("%f %f %f\n", p->ax[0], p->ax[1], p->ax[2]);
	printf("%f %f %f\n", p->e2[0], p->e2[1], p->e2[2]);
	printf("%f %f %f\n", p->e3[0], p->e3[1], p->e3[2]);
	printf("~~~~~\n");
}

void	add_con_axis(t_con *p)
{
	if (fabs(p->ax[0]) <= fabs(p->ax[1]) && fabs(p->ax[0]) <= fabs(p->ax[2]))
		vec_cross(p->e2, (t_v3){1, 0, 0}, p->ax);
	else if (fabs(p->ax[1]) <= fabs(p->ax[2]))
		vec_cross(p->e2, (t_v3){0, 1, 0}, p->ax);
	else
		vec_cross(p->e2, (t_v3){0, 0, 1}, p->ax);
	vec_normalize(p->e2);
	vec_cross(p->e3, p->e2, p->ax);
}

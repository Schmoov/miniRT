/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:48:43 by parden            #+#    #+#             */
/*   Updated: 2025/06/14 18:19:34 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	add_plane_axis(t_pla *p)
{
	if (fabs(p->nor[0]) <= fabs(p->nor[1]) && fabs(p->nor[0]) <= fabs(p->nor[2]))
		vec_cross(p->e2, (t_v3){1, 0, 0}, p->nor);
	else if (fabs(p->nor[1]) <= fabs(p->nor[2]))
		vec_cross(p->e2, (t_v3){0, 1, 0}, p->nor);
	else
		vec_cross(p->e2, (t_v3){0, 0, 1}, p->nor);
	vec_norm(p->e2);
	vec_cross(p->e3, p->e2, p->nor);
}

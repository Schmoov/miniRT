/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:45:30 by parden            #+#    #+#             */
/*   Updated: 2025/06/18 16:06:43 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	bump_normal(t_model *m, t_impact *imp, t_obj *obj)
{
	if (obj->type == PLA)
		bump_pla(m, imp, &obj->pla);
	if (obj->type == SPH)
		bump_sph(m, imp, &obj->sph);
	if (obj->type == CYL)
		bump_cyl(m, imp, &obj->cyl);
	if (obj->type == CON)
		bump_con(m, imp, &obj->con);
}

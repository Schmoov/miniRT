/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:29:34 by parden            #+#    #+#             */
/*   Updated: 2025/06/13 15:00:16 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	eq_quad_solve(t_eq_quad *eq)
{
	float	delta;

	eq->has_solution = false;
	delta = powf(eq->b, 2) - 4 * eq->a * eq->c;
	if (delta < EPS_QUAD)
		return ;
	eq->has_solution = true;
	eq->x1 = (-eq->b + sqrtf(delta)) / (2 * eq->a);
	eq->x1 = (-eq->b - sqrtf(delta)) / (2 * eq->a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:59:27 by parden            #+#    #+#             */
/*   Updated: 2025/04/18 17:41:44 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef float	t_v3[3];
float	vec_norm(t_v3 v);
void	vec_normalize(t_v3 v);
void	vec_move_along(t_v3 point, t_v3 dir, float scale);
void	vec_sub(t_v3 res, t_v3 v1, t_v3 v2);
float	vec_dot(t_v3 v1, t_v3 v2);
void	vec_cross(t_v3 res, t_v3 v1, t_v3 v2);

#endif

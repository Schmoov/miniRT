/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:35:27 by parden            #+#    #+#             */
/*   Updated: 2025/04/16 19:39:59 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H
#include "object.h"

typedef float	t_v3[3];
typedef struct s_ray {
	t_v3	pt;
	t_v3	dir;
}	t_ray;

typedef struct s_cam {
	t_v3	c;

typedef struct s_model {
	t_cam	cam;
	t_light	light;
	t_scene	scene;
}	t_model;

#endif

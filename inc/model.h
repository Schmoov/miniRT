/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:35:27 by parden            #+#    #+#             */
/*   Updated: 2025/04/18 15:01:06 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H
#include "../libft/libft.h"
#include "scene_structs.h"
#include "object.h"

#define W 1280
#define H 720


#define LIT_MAX 20
#define OBJ_MAX 200

typedef unsigned int	t_rgb;
typedef float	t_v3[3];
typedef struct s_ray {
	t_v3	pos;
	t_v3	dir;
}	t_ray;

typedef struct s_cam {
	t_v3	pos;
	t_v3	dir;
	float	fov;
}	t_cam;

typedef struct s_lit {
	t_v3	pos;
	float	lum;
	t_rgb	col;
}	t_lit;

typedef struct s_model {
	t_cam	cam;
	t_lit	amb;
	int		lit_nb;
	t_lit	lit[LIT_MAX];
	int		obj_nb;
	t_obj	obj[OBJ_MAX];
}	t_model;

#endif

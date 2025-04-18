/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:35:27 by parden            #+#    #+#             */
/*   Updated: 2025/04/18 17:57:00 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H
# include <math.h>
# include "../libft/libft.h"
# include "scene_structs.h"
# include "object.h"
# include "model_api.h"
# include "vector.h"

# define W 1280
# define H 720

# define LIT_MAX 20
# define OBJ_MAX 200

typedef unsigned int	t_rgb;
typedef struct s_ray {
	t_v3	pos;
	t_v3	dir;
}	t_ray;

typedef struct s_cam {
	t_v3	pos;
	t_v3	dir;
	float	fov;
	t_v3	vx_scr;
	t_v3	vy_scr;
	t_v3	pos_scr;
	float	w_scr;
	float	h_scr;
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

typedef struct s_impact {
	t_v3	pos;
	t_v3	dir;
	int		obj_idx;
}	t_impact;

#endif

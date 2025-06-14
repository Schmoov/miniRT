/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:35:27 by parden            #+#    #+#             */
/*   Updated: 2025/06/13 18:17:50 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H
# include <math.h>
# include "../libft/libft.h"
# include "scene_structs.h"
# include "object.h"
# include "model_api.h"
# include "math_utils.h"

# define INF 1e9
# define W 1280
# define H 720

# define LIT_MAX 20
# define OBJ_MAX 200

//Discards grazing rays
# define EPS_TGT 1e-9
//Discards solutions of small delta quadratic equations
# define EPS_QUAD 1e-9
//Protects from self intersection
# define EPS_ACNE 1e-3

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
	t_rgb	col;
}	t_lit;

typedef struct s_model {
	t_cam	cam;
	t_rgb	amb;
	int		lit_nb;
	t_lit	lit[LIT_MAX];
	int		obj_nb;
	t_obj	obj[OBJ_MAX];
}	t_model;

typedef struct s_ray {
	t_v3	pos;
	t_v3	dir;
}	t_ray;

typedef struct s_impact {
	t_ray	ray;
	float	scale;
	t_v3	pos;
	int		obj_idx;
	t_rgb	col;
	t_v3	normal;
}	t_impact;

void	model_set_cam_screen(t_cam *c);
void	model_pixel_camray(t_model *m, t_ray *r, int x, int y);
t_rgb	model_pixel(t_model *m, int x, int y);
void	model_impact(t_model *m, t_impact *imp);
t_rgb	model_light(t_model *m, t_impact *imp);
void	model_impact_object(t_model *m, t_impact *imp, int i);
void	impact_plane(t_model *m, t_impact *imp, t_pla *pla);
void	impact_disk(t_model *m, t_impact *imp, t_dsk *dsk);
void	impact_sphere(t_model *m, t_impact *imp, t_sph *sph);
void	impact_cylinder(t_model *m, t_impact *imp, t_cyl *cyl);
void	impact_cone(t_model *m, t_impact *imp, t_con *con);

void	impact_color(t_model *m, t_impact *imp);
void	impact_normal(t_model *m, t_impact *imp);
t_rgb	model_light(t_model *m, t_impact *imp);
t_rgb	color_lit(t_model *m, t_impact *imp);
t_rgb	color_one_lit(t_model *m, t_impact *imp, t_lit *lit);

#endif

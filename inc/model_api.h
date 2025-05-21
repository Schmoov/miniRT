/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model_api.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:16:11 by parden            #+#    #+#             */
/*   Updated: 2025/05/21 19:20:55 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_API_H
# define MODEL_API_H

# include "scene_structs.h"

typedef struct s_model	t_model;
typedef unsigned int	t_rgb;

bool	model_init(t_model *mod);
void	model_destroy(t_model *mod);
void	model_set_cam(t_model *mod, t_camera *cam);
void	model_set_ambient(t_model *mod, t_ambient_lighting *amb);
void	model_add_light(t_model *mod, t_light *l);
void	model_add_plane(t_model *mod, t_plane *p);
void	model_add_sphere(t_model *mod, t_sphere *s);
void	model_add_cylinder(t_model *mod, t_cylinder *c);
//void	model_add_cone(t_model *mod, t_conic *c);

//Returns a pointer to a buffer of pixel or NULL on error
//a pixel is an unsigned int packing 3 bytes 0RGB
//the buffer is malloc'd caller has to free
t_rgb	*model_compute(t_model *mod);

#endif

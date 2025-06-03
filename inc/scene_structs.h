/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:00:39 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/03 10:35:52 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_STRUCTS_H
# define SCENE_STRUCTS_H

# include <stddef.h>

# define RGB_MAX 255
# define RGB_MIN 0
# define FOV_MIN 0
# define FOV_MAX 180

typedef struct s_RGB
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
}						t_RGB;

typedef struct s_coord
{
	float				x;
	float				y;
	float				z;
}						t_coord;

typedef t_coord			t_orientation;

typedef enum e_element_type
{
	AMBIENT_LIGHTING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	UNKNOWN,
	EMPTY
}						t_element_type;

typedef struct s_ambient_lighting
{
	float				ratio;
	t_RGB				color;
}						t_ambient_lighting;

typedef struct s_camera
{
	t_coord				pos;
	t_orientation		orientation;
	float				fov;
}						t_camera;

typedef struct s_light
{
	t_coord				pos;
	float				brightness;
	t_RGB				color;
}						t_light;

typedef struct s_sphere
{
	t_coord				pos;
	float				diameter;
	t_RGB				color;
}						t_sphere;

typedef struct s_plane
{
	t_coord				pos;
	t_orientation		axis;
	t_RGB				color;
}						t_plane;

typedef struct s_cylinder
{
	t_coord				pos;
	t_orientation		axis;
	float				diameter;
	float				height;
	t_RGB				color;
}						t_cylinder;

typedef struct s_scene
{
	t_ambient_lighting	ambient;
	t_camera			camera;

	t_light				*lights;
	size_t				light_count;

	t_sphere			*spheres;
	size_t				sphere_count;

	t_plane				*planes;
	size_t				plane_count;

	t_cylinder			*cylinders;
	size_t				cylinder_count;
}						t_scene;

#endif // SCENE_STRUCTS_H

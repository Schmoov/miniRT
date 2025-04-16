/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:35:27 by parden            #+#    #+#             */
/*   Updated: 2025/04/16 19:17:58 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "model.h"

enum e_obj {
	PLANE,
	SPHERE,
	CYLINDER,
	NB_OBJ
};

typedef struct s_plane {
	t_v3	p;
	t_v3	n;
}	t_plane;

typedef struct s_sphere {
	t_v3	c;
	float	r;
}	t_sphere;

typedef struct s_cylinder {
	t_v3	ax;
	float	r;
	float	h;
}	t_cylinder;

typedef struct s_obj {
	enum e_obj	type;
	union {
		t_plane		p;
		t_sphere	s;
		t_cylinder	c;
	};
}	t_obj;



#endif

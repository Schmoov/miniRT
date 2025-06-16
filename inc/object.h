/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:35:27 by parden            #+#    #+#             */
/*   Updated: 2025/06/16 19:04:42 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include "scene_structs.h"
typedef float			t_v3[3];
typedef unsigned int	t_rgb;

enum e_obj {
	PLA,
	SPH,
	CYL,
	CON,
	DSK,
	NB_OBJ
};

typedef struct	s_bump {
	int	w;
	int	h;
	int	*buf;
}		t_bump;

typedef struct s_pla {
	t_v3	pos;
	t_v3	e2;
	t_v3	e3;
	t_v3	nor;
	bool	check;
	t_rgb	col1;
	t_rgb	col2;
	t_bump	bump;
}	t_pla;

typedef struct s_sph {
	t_v3	pos;
	float	rad;
	bool	check;
	t_rgb	col1;
	t_rgb	col2;
	t_bump	bump;
}	t_sph;

typedef struct s_cyl {
	t_v3	pos;
	t_v3	ax;
	t_v3	e2;
	t_v3	e3;
	t_v3	nor;
	float	rad;
	float	hgt;
	bool	check;
	t_rgb	col1;
	t_rgb	col2;
	t_bump	bump;
}	t_cyl;

typedef struct s_con {
	t_v3	pos;
	t_v3	ax;
	t_v3	e2;
	t_v3	e3;
	float	ang;
	float	hgt;
	bool	check;
	t_rgb	col1;
	t_rgb	col2;
	t_bump	bump;
}	t_con;

typedef struct s_dsk {
	t_v3	pos;
	t_v3	nor;
	t_v3	e2;
	t_v3	e3;
	bool	check;
	t_rgb	col1;
	t_rgb	col2;
	float	rad;
}	t_dsk;

typedef struct s_obj {
	enum e_obj	type;
	union {
		t_pla	pla;
		t_sph	sph;
		t_cyl	cyl;
		t_con	con;
		t_dsk	dsk;
	};
}	t_obj;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:35:27 by parden            #+#    #+#             */
/*   Updated: 2025/06/12 15:54:06 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

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

typedef struct s_pla {
	t_v3	pos;
	t_v3	nor;
	t_rgb	col;
}	t_pla;

typedef struct s_sph {
	t_v3	pos;
	float	rad;
	t_rgb	col;
}	t_sph;

typedef struct s_cyl {
	t_v3	pos;
	t_v3	ax;
	float	rad;
	float	hgt;
	t_rgb	col;
}	t_cyl;

typedef struct s_con {
	t_v3	pos;
	t_v3	ax;
	float	ang;
	float	hgt;
	t_rgb	col;
}	t_con;

typedef struct s_dsk {
	t_v3	pos;
	t_v3	nor;
	t_rgb	col;
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

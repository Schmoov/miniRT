/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:35:27 by parden            #+#    #+#             */
/*   Updated: 2025/04/16 18:45:04 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H

typedef float t_v3[3];

enum e_obj {
	PLANE,
	SPHERE,
	CYLINDER,
	NB_OBJ
};

typedef struct s_plane {
	t_v3 p;
	t_v3 n;
}	t_plane;

typedef struct s_sphere {


#endif

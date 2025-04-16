/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:52:35 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/16 23:16:34 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_ERRORS_H
# define PARSING_ERRORS_H

typedef enum e_parsing_error
{
	ERR_INVALID_AMBIENT_RATIO,
	ERR_INVALID_AMBIENT_COLOR,
	ERR_INVALID_AMBIENT_DUPLICATE,
	ERR_INVALID_CAMERA_POSITION,
	ERR_INVALID_CAMERA_ORIENTATION,
	ERR_INVALID_CAMERA_FOV,
	ERR_INVALID_CAMERA_DUPLICATE,
	ERR_INVALID_CYLINDER_POSITION,
	ERR_INVALID_CYLINDER_AXIS,
	ERR_INVALID_CYLINDER_DIAMETER,
	ERR_INVALID_CYLINDER_HEIGHT,
	ERR_INVALID_CYLINDER_COLOR,
	ERR_INVALID_LIGHT_POSITION,
	ERR_INVALID_LIGHT_BRIGHTNESS,
	ERR_INVALID_LIGHT_COLOR,
	ERR_INVALID_LIGHT_DUPLICATE,
	ERR_INVALID_SPHERE_POSITION,
	ERR_INVALID_SPHERE_DIAMETER,
	ERR_INVALID_SPHERE_COLOR,
	ERR_INVALID_PLANE_POSITION,
	ERR_INVALID_PLANE_AXIS,
	ERR_INVALID_PLANE_COLOR,
	ERR_INVALID_CONE,
	ERR_UNKNOWN_ELEMENT,
	ERR_MEMORY_ALLOCATION,
	NO_ERROR,
    ERR_NO_AMBIENT_LIGHTING,
    ERR_NO_CAMERA,
    ERR_NO_LIGHT,
    ERR_NO_OBJECTS
}	t_parsing_error;

#endif // PARSING_ERRORS_H

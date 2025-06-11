/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:52:35 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/11 15:23:05 by hsoysal          ###   ########.fr       */
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
	ERR_INVALID_SPHERE_POSITION,
	ERR_INVALID_SPHERE_DIAMETER,
	ERR_INVALID_SPHERE_COLOR,
	ERR_INVALID_PLANE_POSITION,
	ERR_INVALID_PLANE_AXIS,
	ERR_INVALID_PLANE_COLOR,
	ERR_INVALID_CONE_POSITION,
	ERR_INVALID_CONE_AXIS,
	ERR_INVALID_CONE_HEIGHT,
	ERR_INVALID_CONE_COLOR,
	ERR_INVALID_CONE_ANGLE,
	ERR_UNKNOWN_ELEMENT,
	ERR_NO_AMBIENT_LIGHTING,
	ERR_NO_CAMERA,
	ERR_NO_LIGHT,
	ERR_NO_OBJECTS,
	ERR_MEMORY_ALLOCATION,
	ERR_BMP_LOAD_FAILED,
	ERR_BMP_FILE_NOT_FOUND,
	ERR_BMP_INVALID_FORMAT,
	ERR_BMP_INVALID_HEADER,
	NO_ERROR
}	t_parsing_error;

#endif // PARSING_ERRORS_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:30:26 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/24 14:57:39 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

#define ERR_MSG_AMBIENT_RATIO "Invalid ambient lighting ratio"
#define ERR_MSG_AMBIENT_COLOR "Invalid ambient lighting color"
#define ERR_MSG_AMBIENT_DUPLICATE "Duplicate ambient lighting definition"
#define ERR_MSG_CAMERA_POSITION "Invalid camera position"
#define ERR_MSG_CAMERA_ORIENTATION "Invalid camera orientation"
#define ERR_MSG_CAMERA_FOV "Invalid camera field of view"
#define ERR_MSG_CAMERA_DUPLICATE "Duplicate camera definition"
#define ERR_MSG_CYLINDER_POSITION "Invalid cylinder position"
#define ERR_MSG_CYLINDER_AXIS "Invalid cylinder axis"
#define ERR_MSG_CYLINDER_DIAMETER "Invalid cylinder diameter"
#define ERR_MSG_CYLINDER_HEIGHT "Invalid cylinder height"
#define ERR_MSG_CYLINDER_COLOR "Invalid cylinder color"
#define ERR_MSG_LIGHT_POSITION "Invalid light position"
#define ERR_MSG_LIGHT_BRIGHTNESS "Invalid light brightness"
#define ERR_MSG_LIGHT_COLOR "Invalid light color"
#define ERR_MSG_LIGHT_DUPLICATE "Duplicate light definition"
#define ERR_MSG_SPHERE_POSITION "Invalid sphere position"
#define ERR_MSG_SPHERE_DIAMETER "Invalid sphere diameter"
#define ERR_MSG_SPHERE_COLOR "Invalid sphere color"
#define ERR_MSG_PLANE_POSITION "Invalid plane position"
#define ERR_MSG_PLANE_AXIS "Invalid plane axis"
#define ERR_MSG_PLANE_COLOR "Invalid plane color"
#define ERR_MSG_CONE "Invalid cone definition"
#define ERR_MSG_UNKNOWN_ELEMENT "Unknown element type"
#define ERR_MSG_MEMORY_ALLOCATION "Memory allocation error"

void	exit_with_error(t_parsing_error err, const char *filename, int num_line)
{
	const char *const	error_message[] = {
		ERR_MSG_AMBIENT_RATIO, ERR_MSG_AMBIENT_COLOR, ERR_MSG_AMBIENT_DUPLICATE,
		ERR_MSG_CAMERA_POSITION, ERR_MSG_CAMERA_ORIENTATION,
		ERR_MSG_CAMERA_FOV, ERR_MSG_CAMERA_DUPLICATE,
		ERR_MSG_CYLINDER_POSITION, ERR_MSG_CYLINDER_AXIS,
		ERR_MSG_CYLINDER_DIAMETER, ERR_MSG_CYLINDER_HEIGHT,
		ERR_MSG_CYLINDER_COLOR, ERR_MSG_LIGHT_POSITION,
		ERR_MSG_LIGHT_BRIGHTNESS, ERR_MSG_LIGHT_COLOR,
		ERR_MSG_LIGHT_DUPLICATE, ERR_MSG_SPHERE_POSITION,
		ERR_MSG_SPHERE_DIAMETER, ERR_MSG_SPHERE_COLOR,
		ERR_MSG_PLANE_POSITION, ERR_MSG_PLANE_AXIS, ERR_MSG_PLANE_COLOR,
		ERR_MSG_CONE, ERR_MSG_UNKNOWN_ELEMENT, ERR_MSG_MEMORY_ALLOCATION,
	};

	printf("\033[31mError\033[0m : \033[33m%s\033[0m ", error_message[err]);
	printf("-> \033[1m%s:%d\033[0m\n", filename, num_line);
	exit(EXIT_FAILURE);
}

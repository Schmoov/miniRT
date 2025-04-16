/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:00:36 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/16 23:20:32 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "parser_utils.h"
#include "parsing_errors.h"
#include "scene_structs.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

t_element_type	get_element_type(const char *line)
{
	if (strncmp(line, "A ", 2) == 0)
		return (AMBIENT_LIGHTING);
	if (strncmp(line, "C ", 2) == 0)
		return (CAMERA);
	if (strncmp(line, "L ", 2) == 0)
		return (LIGHT);
	if (strncmp(line, "sp", 2) == 0)
		return (SPHERE);
	if (strncmp(line, "pl", 2) == 0)
		return (PLANE);
	if (strncmp(line, "cy", 2) == 0)
		return (CYLINDER);
	if (strncmp(line, "co", 2) == 0)
		return (CONE);
	return (UNKNOWN);
}

void	exit_unknown_element(char *line, int file)
{
	printf("Error\nUnknown element type in line: %s\n", line);
	free(line);
	close(file);
	exit(EXIT_FAILURE);
}

void	parse_scene(const char *filename, t_scene *scene)
{
	int				file;
	char			*line;
	int				ambient_set;
	int				camera_set;
	int				light_set;
	t_element_type	type;
	t_parsing_error	error;
	int				num_line;

	ambient_set = 0;
	camera_set = 0;
	light_set = 0;
	error = NO_ERROR;
	file = open(filename, O_RDONLY | O_CLOEXEC);
	if (file == -1)
	{
		printf("Error\nCould not open file: %s\n", filename);
		exit(EXIT_FAILURE);
	}
	line = NULL;
	num_line = 0;
	while ((line = get_next_line(file)) != NULL && error == NO_ERROR)
	{
		type = get_element_type(line);
		switch (type)
		{
		case AMBIENT_LIGHTING:
			if (ambient_set)
			{
				printf("Error\nDuplicate ambient lighting definition\n");
				exit(EXIT_FAILURE);
			}
			parse_ambient_lighting(line, &scene->ambient);
			ambient_set = 1;
			break ;
		case CAMERA:
			if (camera_set)
			{
				printf("Error\nDuplicate camera definition\n");
				exit(EXIT_FAILURE);
			}
			error = parse_camera(line, &scene->camera);
			camera_set = 1;
			break ;
		case LIGHT:
			if (light_set)
			{
				printf("Error\nDuplicate light definition\n");
				exit(EXIT_FAILURE);
			}
			error = parse_light(line, &scene->light);
			light_set = 1;
			break ;
		case SPHERE:
			error = parse_sphere(line, scene);
			break ;
		case PLANE:
			error = parse_plane(line, scene);
			break ;
		case CYLINDER:
			error = parse_cylinder(line, scene);
			break ;
		default:
			error = ERR_UNKNOWN_ELEMENT;
		}
		num_line++;
	}
	free(line);
	close(file);
	if (ambient_set == 0)
		error = ERR_NO_AMBIENT_LIGHTING;
	if (camera_set == 0)
		error = ERR_NO_CAMERA;
	if (light_set == 0)
		error = ERR_NO_LIGHT;
	if (error != NO_ERROR)
		exit_with_error(error, filename, num_line);
}

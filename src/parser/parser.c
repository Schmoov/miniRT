/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:00:36 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/17 21:37:10 by hsoysal          ###   ########.fr       */
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
	if (strncmp(line, "\n", 1) == 0)
		return (EMPTY);
	return (UNKNOWN);
}

void	exit_unknown_element(char *line, int file)
{
	printf("Error\nUnknown element type in line: %s\n", line);
	free(line);
	close(file);
	exit(EXIT_FAILURE);
}

t_parsing_error	parse_line(char *line, t_scene *scene)
{
	t_element_type	type;
	t_parsing_error	error;

	error = NO_ERROR;
	type = get_element_type(line);
	if (type == AMBIENT_LIGHTING)
		error = parse_ambient_lighting(line, &scene->ambient);
	if (type == CAMERA)
		error = parse_camera(line, &scene->camera);
	if (type == LIGHT)
		error = parse_light(line, &scene->light);
	if (type == SPHERE)
		error = parse_sphere(line, scene);
	if (type == PLANE)
		error = parse_plane(line, scene);
	if (type == CYLINDER)
		error = parse_cylinder(line, scene);
	if (type == EMPTY)
		return (NO_ERROR);
	if (type == UNKNOWN)
		error = ERR_UNKNOWN_ELEMENT;
	return (error);
}

void	parse_scene(const char *filename, t_scene *scene)
{
	int				file;
	char			*line;
	t_parsing_error	error;
	int				num_line;

	error = NO_ERROR;
	file = open(filename, O_RDONLY | O_CLOEXEC);
	if (file == -1)
	{
		printf("Error\nCould not open file: %s\n", filename);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(file);
	num_line = 0;
	while (line != NULL && error == NO_ERROR)
	{
		error = parse_line(line, scene);
		num_line++;
		line = get_next_line(file);
	}
	free(line);
	close(file);
	if (error != NO_ERROR)
		exit_with_error(error, filename, num_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:00:36 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/21 18:23:32 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

t_element_type	get_element_type(const char *line)
{
	if (ft_strncmp(line, "A ", 2) == 0)
		return (AMBIENT_LIGHTING);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (CAMERA);
	if (ft_strncmp(line, "L ", 2) == 0)
		return (LIGHT);
	if (ft_strncmp(line, "sp ", 3) == 0)
		return (SPHERE);
	if (ft_strncmp(line, "pl", 2) == 0)
		return (PLANE);
	if (ft_strncmp(line, "cy", 2) == 0)
		return (CYLINDER);
	if (ft_strncmp(line, "co", 2) == 0)
		return (CONE);
	if (ft_strncmp(line, "\n", 1) == 0 || ft_strncmp(line, "#", 1) == 0)
		return (EMPTY);
	return (UNKNOWN);
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
		error = parse_light(line, scene);
	if (type == SPHERE)
		error = parse_sphere(line, scene);
	if (type == PLANE)
		error = parse_plane(line, scene);
	if (type == CYLINDER)
		error = parse_cylinder(line, scene);
	if (type == CONE)
		error = parse_cone(line, scene);
	if (type == EMPTY)
		return (NO_ERROR);
	if (type == UNKNOWN)
		error = ERR_UNKNOWN_ELEMENT;
	return (error);
}

void	parse_scene(const char *filename, t_scene *scene)
{
	char	*line;
	int		num_line;

	t_parsing_error(error) = NO_ERROR;
	int(file) = open(filename, O_RDONLY | O_CLOEXEC);
	if (file == -1)
	{
		printf("\033[31mError\033[0m \033[33mCould not open file: \033[1m%s\033[0m\n",
			filename);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(file);
	num_line = 0;
	while (line != NULL && error == NO_ERROR)
	{
		error = parse_line(line, scene);
		num_line++;
		free(line);
		line = get_next_line(file);
	}
	close(file);
	if (error != NO_ERROR)
		return (free(line), free_scene(scene), exit_with_error(error, filename,
				num_line));
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, new_size);
		free(ptr);
	}
	return (new_ptr);
}

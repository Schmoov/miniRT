/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:20:58 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/11 20:01:33 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/model.h"
#include "../inc/model_api.h"
#include <string.h>

void	init_my_model(t_model *m, t_scene *s)
{
	size_t	i;

	model_init(m);
	model_set_cam(m, &s->camera);
	model_set_ambient(m, &s->ambient);
	i = -1;
	while (++i < s->light_count)
		model_add_light(m, &s->lights[i]);
	i = -1;
	while (++i < s->plane_count)
		model_add_plane(m, &s->planes[i]);
	i = -1;
	while (++i < s->sphere_count)
		model_add_sphere(m, &s->spheres[i]);
	i = -1;
	while (++i < s->cylinder_count)
		model_add_cylinder(m, &s->cylinders[i]);
	// i = -1;
	// while (++i < s->cone_count)
	// 	model_add_cone(m, &s->cones[i]);
	free_scene(s);
}

const char	*get_filename(int argc, char **argv)
{
	char	*filename;
	size_t	len;

	filename = argv[1];
	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <scene_file.rt>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(filename);
	if (len < 3 || ft_strcmp(filename + len - 3, ".rt") != 0)
	{
		ft_printf("Error\nInvalid file extension. Expected a .rt file\n");
		exit(EXIT_FAILURE);
	}
	return (filename);
}

int	main(int argc, char **argv)
{
	const char	*filename;
	t_model		model;
	t_scene		scene;
	t_rgb		*image;

	filename = get_filename(argc, argv);
	ft_memset(&scene, 0, sizeof(t_scene));
	parse_scene(filename, &scene);
	init_my_model(&model, &scene);
	printf("Scene parsed successfully!\n");
	image = model_compute(&model);
	display_image(image);
	return (EXIT_SUCCESS);
}

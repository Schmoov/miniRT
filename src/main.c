/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:20:58 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/24 14:54:23 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

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

t_RGB	*compute(t_scene *scene)
{
	t_RGB	*image;

	(void)scene;
	image = malloc(sizeof(t_RGB) * WIDTH * HEIGHT);
	if (!image)
	{
		perror("Failed to allocate memory for image");
		free_scene(scene);
		exit(EXIT_FAILURE);
	}
	int (i) = -1;
	while (++i < WIDTH * HEIGHT)
	{
		image[i].r = (i + 1) / ((float)(WIDTH * HEIGHT) / 255.F);
		image[i].g = (float)((i + 1) % WIDTH) / ((float)WIDTH / 255.F);
		image[i].b = (i + 1) / ((float)(WIDTH * HEIGHT) / 255.F);
	}
	return (image);
}

int	main(int argc, char **argv)
{
	const char	*filename;

	t_scene(scene) = {0};
	filename = get_filename(argc, argv);
	parse_scene(filename, &scene);
	printf("Scene parsed successfully!\n");
	t_RGB *(image) = compute(&scene);
	free_scene(&scene);
	display_image(image);
	return (EXIT_SUCCESS);
}

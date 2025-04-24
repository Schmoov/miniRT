/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:20:58 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/24 15:24:54 by parden           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	const char	*filename;

	t_scene(scene) = {0};
	filename = get_filename(argc, argv);
	parse_scene(filename, &scene);
	printf("Scene parsed successfully!\n");
	t_rgb *(image) = compute(&scene);
	free_scene(&scene);
	display_image(image);
	return (EXIT_SUCCESS);
}

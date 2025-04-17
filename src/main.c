/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:20:58 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/18 00:40:38 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "parser/parser.h"
#include "parser/scene_structs.h"
#include <stdio.h>
#include <stdlib.h>

const char	*get_filename(int argc, char **argv)
{
	char	*filename;
	size_t	len;

	filename = argv[1];
	if (argc != 2)
	{
		printf("Error\nUsage: %s <scene_file.rt>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(filename);
	if (len < 3 || ft_strcmp(filename + len - 3, ".rt") != 0)
	{
		printf("Error\nInvalid file extension. Expected a .rt file\n");
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
	free_scene(&scene);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:15:20 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/20 14:32:44 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

static void	free_damier_and_heightmap(t_damier *damier, t_heightmap *heightmap)
{
	if (damier)
		free(damier);
	if (heightmap)
		free_heightmap(heightmap);
}

static void	free_bonus(t_scene *scene)
{
	int	i;

	i = -1;
	while ((size_t)++i < scene->plane_count)
		free_damier_and_heightmap(scene->planes[i].damier,
			scene->planes[i].heightmap);
	i = -1;
	while ((size_t)++i < scene->sphere_count)
		free_damier_and_heightmap(scene->spheres[i].damier,
			scene->spheres[i].heightmap);
	i = -1;
	while ((size_t)++i < scene->cylinder_count)
		free_damier_and_heightmap(scene->cylinders[i].damier,
			scene->cylinders[i].heightmap);
	i = -1;
	while ((size_t)++i < scene->cone_count)
		free_damier_and_heightmap(scene->cones[i].damier,
			scene->cones[i].heightmap);
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	free_bonus(scene);
	free(scene->lights);
	free(scene->planes);
	free(scene->spheres);
	free(scene->cylinders);
	free(scene->cones);
}

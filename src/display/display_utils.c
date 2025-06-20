/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:01:26 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/20 13:26:05 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

void	clear_all(t_application *app)
{
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_image(app->mlx, app->img);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(0);
}

void	initialize_mlx(t_application *app, t_rgb *image)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (perror("Failed to initialize mlx"), free(image),
			exit(EXIT_FAILURE));
	app->win = mlx_new_window(app->mlx, WIDTH, HEIGHT, "miniRT");
	if (!app->win)
	{
		perror("Failed to create window");
		free(image);
		free(app->mlx);
		exit(EXIT_FAILURE);
	}
	app->img = mlx_new_image(app->mlx, WIDTH, HEIGHT);
	if (!app->img)
	{
		perror("Failed to create image");
		free(image);
		free(app->win);
		free(app->mlx);
		exit(EXIT_FAILURE);
	}
	app->data_addr = mlx_get_data_addr(app->img, &app->bpp, &app->size_line,
			&app->endian);
}

int	*get_pixel_at(t_application *app, int x, int y)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (NULL);
	return ((int *)(app->data_addr + (y * app->size_line + x * (app->bpp
				/ 8))));
}

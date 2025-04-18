/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:47:43 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/18 06:47:37 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../parser/scene_structs.h"
#include "display.h"
#include <stdlib.h>

typedef struct s_application
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
}			t_application;

int	convert_rgb_to_bin(t_RGB *color)
{
	return ((color->r << 16) | (color->g << 8) | color->b);
}

void	clear_all(t_application *app)
{
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_image(app->mlx, app->img);
	free(app->data_addr);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(0);
}

void	display_image(t_RGB *image)
{
	char	*data_addr;

	t_application(app) = {0};
	int color, (bpp), size_line, endian, x, y = -1;
	app.mlx = mlx_init();
	if (!app.mlx)
		return (free(image));
	app.win = mlx_new_window(app.mlx, WIDTH, HEIGHT, "MiniRT");
	app.img = mlx_new_image(app.mlx, WIDTH, HEIGHT);
	data_addr = mlx_get_data_addr(app.img, &bpp, &size_line, &endian);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			color = convert_rgb_to_bin(&image[(y * WIDTH) + x]);
			*(int *)(data_addr + (y * size_line + x * (bpp / 8))) = color;
		}
	}
	free(image);
	mlx_put_image_to_window(app.mlx, app.win, app.img, 0, 0);
	mlx_hook(app.win, 17, 0, (void *)clear_all, &app);
	mlx_loop(app.mlx);
}

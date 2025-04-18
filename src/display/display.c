/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:47:43 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/18 06:14:43 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../parser/scene_structs.h"
#include "display.h"

int	convert_rgb_to_bin(t_RGB *color)
{
	return ((color->r << 16) | (color->g << 8) | color->b);
}

void	display_image(t_RGB *image)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;

	int color, (bpp), size_line, endian, x, y = -1;
	mlx = mlx_init();
	if (!mlx)
		return (free(image));
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "MiniRT");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	data_addr = mlx_get_data_addr(img, &bpp, &size_line, &endian);
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
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
}

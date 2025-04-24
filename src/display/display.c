/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:47:43 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/24 15:18:07 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

int	convert_rgb_to_bin(t_RGB *color);
void	display_image(t_RGB *image)
{
	t_application(app) = {0};
	int color, (x), y = -1;
	initialize_mlx(&app, image);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			color = convert_rgb_to_bin(&image[(y * WIDTH) + x]);
			*get_pixel_at(&app, x, y) = color;
		}
	}
	free(image);
	mlx_put_image_to_window(app.mlx, app.win, app.img, 0, 0);
	mlx_hook(app.win, 17, 0, (void *)clear_all, &app);
	mlx_loop(app.mlx);
}

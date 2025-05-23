/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:47:43 by hsoysal           #+#    #+#             */
/*   Updated: 2025/05/19 20:01:28 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

int	escape_key_close(int keycode, void *param)
{
	t_application	*app;

	app = (t_application *)param;
	if (keycode == 65307)
		clear_all(app);
	return (0);
}

void	display_image(t_rgb *image)
{
	t_application(app) = {0};
	int (x), y = -1;
	initialize_mlx(&app, image);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			*get_pixel_at(&app, x, y) = image[(y * WIDTH) + x];
		}
	}
	free(image);
	mlx_put_image_to_window(app.mlx, app.win, app.img, 0, 0);
	mlx_hook(app.win, 17, 0, (void *)clear_all, &app);
	mlx_key_hook(app.win, escape_key_close, &app);
	mlx_loop(app.mlx);
}

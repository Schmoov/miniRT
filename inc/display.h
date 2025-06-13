/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:52:34 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/13 15:04:00 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

typedef unsigned int	t_rgb;
typedef struct s_application
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_application;

int			*get_pixel_at(t_application *app, int x, int y);
void		clear_all(t_application *app);
void		initialize_mlx(t_application *app, t_rgb *image);
void		display_image(t_rgb *image);

#endif // DISPLAY_H

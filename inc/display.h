/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:52:34 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/24 14:46:08 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

typedef struct s_RGB t_RGB;
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
void		initialize_mlx(t_application *app, t_RGB *image);
void		display_image(t_RGB *image);

#endif // DISPLAY_H

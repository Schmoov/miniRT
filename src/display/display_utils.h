/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:01:36 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/19 01:04:40 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_UTILS_H
# define DISPLAY_UTILS_H

# include "../parser/scene_structs.h"

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
int			convert_rgb_to_bin(t_RGB *color);
void		clear_all(t_application *app);
void		initialize_mlx(t_application *app, t_RGB *image);

#endif // DISPLAY_UTILS_H

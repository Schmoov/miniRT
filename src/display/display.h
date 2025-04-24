/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 03:52:34 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/19 00:35:58 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# define WIDTH 1024
# define HEIGHT 768

# include "../../mlx/mlx.h"
# include "../parser/scene_structs.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	display_image(t_RGB *image);

#endif // DISPLAY_H

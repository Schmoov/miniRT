/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:02:01 by parden            #+#    #+#             */
/*   Updated: 2025/05/04 14:13:10 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RED 0xff0000
# define GRN 0xff00
# define BLU 0xff

typedef unsigned int t_rgb;

t_rgb	color_mult(t_rgb c1, t_rgb c2);
t_rgb	color_add(t_rgb c1, t_rgb c2);
t_rgb	color_scale(t_rgb c, float f);

#endif

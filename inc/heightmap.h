/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightmap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 00:00:00 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/10 22:09:32 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEIGHTMAP_H
# define HEIGHTMAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>

typedef struct s_heightmap
{
	unsigned char	**data;
	int				width;
	int				height;
}					t_heightmap;

t_heightmap	*load_bmp_heightmap(const char *filename);
void		free_heightmap(t_heightmap *hmap);

#endif

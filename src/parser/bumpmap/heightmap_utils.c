/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightmap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:08:29 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/11 12:47:15 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/parser.h"
#include <stdlib.h>

void	free_heightmap(t_heightmap *hmap)
{
	int	i;

	if (!hmap)
		return ;
	if (hmap->data)
	{
		i = -1;
		while (++i < hmap->height)
			if (hmap->data[i])
				free(hmap->data[i]);
		free(hmap->data);
	}
	free(hmap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightmap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:08:29 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/11 15:12:09 by hsoysal          ###   ########.fr       */
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

t_parsing_error	parse_heightmap(char *line, t_heightmap **heightmap)
{
	t_heightmap		*hmap;
	t_parsing_error	err;

	if (!line || *line == '\0' || *line == '\n')
		return (NO_ERROR);
	int (i) = -1;
	while (line[++i])
	{
		if (line[i] == '\n' || line[i] == '\r' || line[i] == ' ')
		{
			line[i] = '\0';
			break ;
		}
	}
	hmap = malloc(sizeof(t_heightmap));
	if (!hmap)
		return (ERR_MEMORY_ALLOCATION);
	err = load_bmp_heightmap(line, hmap);
	if (err != NO_ERROR)
		return (free(hmap), err);
	*heightmap = hmap;
	return (NO_ERROR);
}

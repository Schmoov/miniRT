/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heightmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 00:00:00 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/18 18:57:29 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/parser.h"
#include "../../../libft/libft.h"

static unsigned char	**allocate_matrix(int width, int height)
{
	unsigned char	**matrix;
	int				i;

	matrix = malloc(sizeof(unsigned char *) * height);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = malloc(sizeof(unsigned char) * width);
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

static int	parse_header(char *line, int *width, int *height)
{
	char	**parts;

	if (!line || ft_strncmp(line, "BM ", 3) != 0)
		return (0);
	parts = ft_split(line, ' ');
	if (!parts || !parts[1] || !parts[2])
	{
		if (parts)
			ft_free_split(parts);
		return (0);
	}
	*width = ft_atoi(parts[1]);
	*height = ft_atoi(parts[2]);
	ft_free_split(parts);
	return (*width > 0 && *height > 0);
}

static int	parse_heightmap_line(char *line, unsigned char *row, int width)
{
	char	**values;
	int		i;
	int		count;

	if (!line)
		return (0);
	values = ft_split(line, ' ');
	if (!values)
		return (0);
	count = 0;
	while (values[count])
		count++;
	if (count != width)
		return (ft_free_split(values), 0);
	i = -1;
	while (++i < width)
		row[i] = (unsigned char)ft_atoi(values[i]);
	ft_free_split(values);
	return (1);
}

static t_parsing_error	fill_heightmap_data(t_heightmap *hmap, int fd)
{
	int		y;
	char	*line;

	y = 0;
	line = get_next_line(fd);
	while (y < hmap->height && line)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) > 0)
		{
			if (!parse_heightmap_line(line, hmap->data[y], hmap->width))
				return (free(line), ERR_BMP_INVALID_FORMAT);
			y++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		free(line);
	return (NO_ERROR);
}

t_parsing_error	load_bmp_heightmap(const char *filename, t_heightmap *hmap)
{
	int		fd;
	char	*header_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERR_BMP_FILE_NOT_FOUND);
	header_line = get_next_line(fd);
	if (!header_line)
		return (close(fd), ERR_BMP_INVALID_HEADER);
	if (header_line[ft_strlen(header_line) - 1] == '\n')
		header_line[ft_strlen(header_line) - 1] = '\0';
	if (!parse_header(header_line, &hmap->width, &hmap->height))
		return (free(header_line), close(fd), ERR_BMP_INVALID_HEADER);
	free(header_line);
	hmap->data = allocate_matrix(hmap->width, hmap->height);
	if (!hmap->data)
		return (close(fd), ERR_MEMORY_ALLOCATION);
	fill_heightmap_data(hmap, fd);
	close(fd);
	return (NO_ERROR);
}

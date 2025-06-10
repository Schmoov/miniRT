#include "../../inc/heightmap.h"
#include "../../libft/libft.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char const *argv[])
{
	t_heightmap	*hmap;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <bmp_file>\n", argv[0]);
		return (1);
	}
	hmap = load_bmp_heightmap(argv[1]);
	if (!hmap)
	{
		fprintf(stderr, "Failed to load heightmap from %s\n", argv[1]);
		return (1);
	}
	free_heightmap(hmap);
	return (0);
}

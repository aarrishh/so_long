#include "includes/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

void	check_file(char *file)
{
	int i;
	int res;

	i = 0;
	while (file[i])
	{
		while (file[i] != '.' && file[i])
			i++;
		res = ft_strcmp((file + i), ".ber");
		if (res != 0)
		{
			write (1, "Invalid map's name!\n", 20);
			exit(5);
		}
		else
			break;
	}
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->count_P = 0;
	map->count_E = 0;
	map->count_C = 0;
	map->player.pos_x = -1;
	map->player.pos_y = -1;
	map->player.e_pos_y = -1;
	map->player.e_pos_x = -1;
}

int main(int argc, char **argv)
{
	char		**res;
	t_map		map;

	init_map(&map);
	res = NULL;
	if (argc == 2)
	{
		check_file(argv[1]);
		res = gnl_call(argv[1]);
		if (!res || !(*res))
		{
			free(res);
			print_error();
		}
		check(res, &map);
		// free_matrix(res);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}




















// if mer nishy = 0 |> i+1 (esi while-i mej)
// if n < 0 or i >= n or j < n or j >= m or kubiky != 0 |> return;


























// void zibilanoc(void)
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	// int		img_width = 4000;
// 	// int		img_height = 3500;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 3500, 2800, "XPM Image");
// 	int i = 0;
// 	while(i < 2)
// 	{
// 		// img = mlx_xpm_file_to_image(mlx, "images/fon.xpm", &img_width, &img_height);
// 		// if (!img)
// 		// {
// 		// 	("Failed to load image: images/fon.xpm\n");
// 		// 	return (1);
// 		// }
// 		// if (i == 0)
// 		// 	mlx_put_image_to_window(mlx, win, img, 0, 0);
// 		// else
// 		// 	mlx_put_image_to_window(mlx, win, img, 300, 500);

// 		// i++;
// 	}
// 	mlx_loop(mlx);
// }

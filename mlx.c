/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:18:12 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/10 18:32:57 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	set_image(t_map *map, char **str, int *img_width, int *img_height)
{
	map->game.win = mlx_new_window(map->game.mlx,
			map->width * TILE, map->height * TILE, "Minion's game");
	map->game.img_bg = mlx_xpm_file_to_image(map->game.mlx,
			"textures/background.xpm", img_width, img_height);
	map->game.img_c = mlx_xpm_file_to_image(map->game.mlx,
			"textures/bananchik.xpm", img_width, img_height);
	map->game.img_p = mlx_xpm_file_to_image(map->game.mlx,
			"textures/minion.xpm", img_width, img_height);
	map->game.img_m = mlx_xpm_file_to_image(map->game.mlx,
			"textures/monster.xpm", img_width, img_height);
	map->game.img_m2 = mlx_xpm_file_to_image(map->game.mlx,
			"textures/monster_2.xpm", img_width, img_height);
	map->game.img_w = mlx_xpm_file_to_image(map->game.mlx,
			"textures/wall.xpm", img_width, img_height);
	map->game.img_c_e = mlx_xpm_file_to_image(map->game.mlx,
			"textures/close_door.xpm", img_width, img_height);
	map->game.img_o_e = mlx_xpm_file_to_image(map->game.mlx,
			"textures/open_door.xpm", img_width, img_height);
	if (!map->game.img_bg || !map->game.img_c
		|| !map->game.img_p || !map->game.img_m || !map->game.img_m2)
	{
		write(1, "Failed to load one or more images\n", 35);
		free_matrix(str);
		exit(1);
	}
}

void	put_image_for_monster_mlx(t_map *map, int x, int y)
{
	void	*monster_img;

	if ((map->frame_count / 30) % 2 == 0)
		monster_img = map->game.img_m;
	else
		monster_img = map->game.img_m2;
	mlx_put_image_to_window(map->game.mlx, map->game.win,
		monster_img, x * TILE, y * TILE);
}

void	if_tile_equal_symbol_mlx(t_map *map, char **str, int x, int y)
{
	char	tile;

	tile = str[y][x];
	mlx_put_image_to_window(map->game.mlx, map->game.win,
		map->game.img_bg, x * TILE, y * TILE);
	if (tile == 'C')
		mlx_put_image_to_window(map->game.mlx, map->game.win,
			map->game.img_c, x * TILE, y * TILE);
	else if (tile == 'P')
		mlx_put_image_to_window(map->game.mlx, map->game.win,
			map->game.img_p, x * TILE, y * TILE);
	else if (tile == 'M')
		put_image_for_monster_mlx(map, x, y);
	else if (tile == '1')
		mlx_put_image_to_window(map->game.mlx, map->game.win,
			map->game.img_w, x * TILE, y * TILE);
	else if (tile == 'E')
		mlx_put_image_to_window(map->game.mlx, map->game.win,
			map->game.img_c_e, x * TILE, y * TILE);
}

void	mlx(char **str, t_map *map)
{
	int	x;
	int	y;
	int	img_width;
	int	img_height;

	map->grid = str;
	map->game.mlx = mlx_init();
	set_image(map, str, &img_width, &img_height);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if_tile_equal_symbol_mlx(map, str, x, y);
			x++;
		}
		y++;
	}
	mlx_hook(map->game.win, 17, 0, close_window, NULL);
	mlx_hook(map->game.win, 2, 1, handle_keypress, map);
	mlx_hook(map->game.win, 3, 2, handle_keyrelease, map);
	mlx_loop_hook(map->game.mlx, (int (*)(void *))game_loop, map);
	mlx_loop(map->game.mlx);
}

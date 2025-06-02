/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:06:47 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/01 19:50:24 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	keypress_wrapper(int keycode, void *param)
{
	t_map *map = (t_map *)param;
	return handle_keypress(keycode, map);
}

void	redraw(t_map *map)
{
	int		y = 0;
	int		x;
	char	tile;

	mlx_clear_window(map->game.mlx, map->game.win);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			tile = map->grid[y][x];
			mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_bg, x * TILE, y * TILE);
			if (tile == '1')
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_w, x * TILE, y * TILE);
			else if (tile == 'P')
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_p, x * TILE, y * TILE);
			else if (tile == 'C')
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_c, x * TILE, y * TILE);
			else if (tile == 'E')
			{
				if (map->count_C != 0)
					mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_c_e, x * TILE, y * TILE);
				else
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_o_e, x * TILE, y * TILE);
			}
				else if (tile == 'M')
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_m, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}


int	handle_keypress(int keycode, t_map *map)
{
	int	new_x = map->player.pos_x;
	int	new_y = map->player.pos_y;

	if (keycode == ESC)
		exit(0);
	else if (keycode == UP)
		new_y--;
	else if (keycode == DOWN)
		new_y++;
	else if (keycode == LEFT)
		new_x--;
	else if (keycode == RIGHT)
		new_x++;
	if (map->grid[new_y][new_x] != '1')
	{
		if (map->grid[new_y][new_x] == 'C')
		{
			if (map->player.pos_x == map->player.e_pos_x 
				&& map->player.pos_y == map->player.e_pos_y)
				map->grid[map->player.pos_y][map->player.pos_x] = 'E';
			else
				map->grid[map->player.pos_y][map->player.pos_x] = '0';
			map->grid[new_y][new_x] = 'P';
			map->count_C--;
			map->player.pos_x = new_x;
			map->player.pos_y = new_y;
		}
		else if (map->grid[new_y][new_x] == 'M')
			exit(1);
		else if (map->grid[new_y][new_x] == 'E')
		{
			if (map->count_C == 0)
				exit(1);
			else
			{
				map->grid[map->player.pos_y][map->player.pos_x] = '0';
				map->grid[new_y][new_x] = 'P';
				map->player.pos_x = new_x;
				map->player.pos_y = new_y;
				map->player.e_pos_x = new_x;
				map->player.e_pos_y = new_x;
			}
		}
		else
		{
			if (map->player.pos_x == map->player.e_pos_x && 
				map->player.pos_y == map->player.e_pos_y)
				map->grid[map->player.pos_y][map->player.pos_x] = 'E';
			else
				map->grid[map->player.pos_y][map->player.pos_x] = '0';
			map->grid[new_y][new_x] = 'P';
			map->player.pos_x = new_x;
			map->player.pos_y = new_y;
		}
	}
	redraw(map);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	mlx(char **str, t_map *map)
{
	int		x;
	int		y;
	int		img_width;
	int		img_height;

	map->grid = str;
	map->game.mlx = mlx_init();
	map->game.win = mlx_new_window(map->game.mlx, map->width * TILE, map->height * TILE, "Minion's game");

	map->game.img_bg = mlx_xpm_file_to_image(map->game.mlx, "images/background.xpm", &img_width, &img_height);
	map->game.img_c = mlx_xpm_file_to_image(map->game.mlx, "images/bananchik.xpm", &img_width, &img_height);
	map->game.img_p = mlx_xpm_file_to_image(map->game.mlx, "images/minion.xpm", &img_width, &img_height);
	map->game.img_m = mlx_xpm_file_to_image(map->game.mlx, "images/monster.xpm", &img_width, &img_height);
	map->game.img_w = mlx_xpm_file_to_image(map->game.mlx, "images/wall.xpm", &img_width, &img_height);
	map->game.img_c_e = mlx_xpm_file_to_image(map->game.mlx, "images/close_door.xpm", &img_width, &img_height);
	map->game.img_o_e = mlx_xpm_file_to_image(map->game.mlx, "images/open_door.xpm", &img_width, &img_height);
	if (!map->game.img_bg || !map->game.img_c || !map->game.img_p || !map->game.img_m)
	{
		printf("Failed to load one or more images\n");
		return ;
	}
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			char tile = str[y][x];
			mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_bg, x * TILE, y * TILE);
			if (tile == 'C')
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_c, x * TILE, y * TILE);
			else if (tile == 'P')
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_p, x * TILE, y * TILE);
			else if (tile == 'M')
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_m, x * TILE, y * TILE);
			else if (tile == '1')
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_w, x * TILE, y * TILE);
			else if (tile == 'E')
				mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_c_e, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
	mlx_hook(map->game.win, 17, 0, close_window, NULL);
	mlx_key_hook(map->game.win, handle_keypress, NULL);
	mlx_key_hook(map->game.win, keypress_wrapper, map);
	mlx_loop(map->game.mlx);
}

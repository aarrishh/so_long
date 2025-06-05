/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:14:00 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/05 22:42:07 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	game_loop(t_map *map)
{
	map->frame_count += 1;
	if (map->key_pressed && map->frame_count % 2000 == 0)
		move_player(map);
	if (map->frame_count % 300 == 0)
		redraw(map);
}

void	if_tile_equal_symbol_redraw(t_map *map, int x, int y)
{
	char	tile;

	tile = map->grid[y][x];
	if (tile == '1')
		mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_w,
			x * TILE, y * TILE);
	else if (tile == 'P')
		mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_p,
			x * TILE, y * TILE);
	else if (tile == 'C')
		mlx_put_image_to_window(map->game.mlx, map->game.win, map->game.img_c,
			x * TILE, y * TILE);
	else if (tile == 'E')
	{
		if (map->count_c != 0)
			mlx_put_image_to_window(map->game.mlx, map->game.win,
				map->game.img_c_e, x * TILE, y * TILE);
		else
			mlx_put_image_to_window(map->game.mlx, map->game.win,
				map->game.img_o_e, x * TILE, y * TILE);
	}
	else if (tile == 'M')
	{
		void *monster_img;
		if ((map->frame_count / 5000) % 2 == 0)
			monster_img = map->game.img_m;
		else
			monster_img = map->game.img_m2;
		mlx_put_image_to_window(map->game.mlx, map->game.win,
			monster_img, x * TILE, y * TILE);
	}
}

void	redraw(t_map *map)
{
	int		y;
	int		x;
	char	*steps_str;

	y = 0;
	mlx_clear_window(map->game.mlx, map->game.win);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_put_image_to_window(map->game.mlx, map->game.win,
				map->game.img_bg, x * TILE, y * TILE);
			if_tile_equal_symbol_redraw(map, x, y);
			x++;
		}
		y++;
	}
	steps_str = ft_itoa(map->steps);
	mlx_string_put(map->game.mlx, map->game.win, 46, 58, 0x0000FF, steps_str);
	free(steps_str);
}

int	close_window(void *param)
{
	(void)param;
	write (1, "Why don't you play?\n", 21);
	exit(0);
	return (0);
}

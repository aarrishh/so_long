/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:09:07 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/05 19:47:03 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	case_e(t_map *map, int new_x, int new_y)
{
	if (map->count_c == 0)
	{
		write (1, "Congratulations, you win <3\n", 29);
		free_matrix(map->grid);
		exit(0);
	}
	else
	{
		map->grid[map->player.pos_y][map->player.pos_x] = '0';
		map->grid[new_y][new_x] = 'P';
		map->player.e_pos_x = new_x;
		map->player.e_pos_y = new_y;
		map->steps++;
	}
}

void	case_c(t_map *map, int new_x, int new_y)
{
	if (map->player.pos_x == map->player.e_pos_x
		&& map->player.pos_y == map->player.e_pos_y)
		map->grid[map->player.pos_y][map->player.pos_x] = 'E';
	else
		map->grid[map->player.pos_y][map->player.pos_x] = '0';
	map->grid[new_y][new_x] = 'P';
	map->count_c--;
	map->steps++;
}

void	else_(t_map *map, int new_x, int new_y)
{
	if (map->player.pos_x == map->player.e_pos_x
		&& map->player.pos_y == map->player.e_pos_y)
		map->grid[map->player.pos_y][map->player.pos_x] = 'E';
	else
		map->grid[map->player.pos_y][map->player.pos_x] = '0';
	map->grid[new_y][new_x] = 'P';
	map->steps++;
}

void	check_moves(t_map *map, int *new_x, int *new_y)
{
	if (map->key_pressed == UP || map->key_pressed == KEY_W)
		(*new_y)--;
	else if (map->key_pressed == DOWN || map->key_pressed == KEY_S)
		(*new_y)++;
	else if (map->key_pressed == LEFT || map->key_pressed == KEY_A)
		(*new_x)--;
	else if (map->key_pressed == RIGHT || map->key_pressed == KEY_D)
		(*new_x)++;
}

void	move_player(t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = map->player.pos_x;
	new_y = map->player.pos_y;
	check_moves(map, &new_x, &new_y);
	if (map->grid[new_y][new_x] != '1')
	{
		if (map->grid[new_y][new_x] == 'C')
			case_c(map, new_x, new_y);
		else if (map->grid[new_y][new_x] == 'M')
		{
			write(1, "The monster ate the minion, but it's \
okay, play again :)\n", 58);
			free_matrix(map->grid);
			exit(1);
		}
		else if (map->grid[new_y][new_x] == 'E')
			case_e(map, new_x, new_y);
		else
			else_(map, new_x, new_y);
		map->player.pos_x = new_x;
		map->player.pos_y = new_y;
		redraw(map);
	}
}

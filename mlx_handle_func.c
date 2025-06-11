/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 18:20:20 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/11 14:38:43 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	handle_keypress(int keycode, t_map *map)
{
	if (keycode == ESC)
	{
		write (1, "Why don't you play?\n", 21);
		free_matrix(map->grid);
		exit(0);
	}
	else if (keycode == RIGHT || keycode == LEFT
		|| keycode == UP || keycode == DOWN
		|| keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		map->key_pressed = keycode;
	return (0);
}

int	handle_keyrelease(int keycode, t_map *map)
{
	if (keycode == map->key_pressed)
		map->key_pressed = 0;
	return (0);
}

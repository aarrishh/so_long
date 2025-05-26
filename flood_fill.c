/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:14:20 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/26 22:19:11 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	player_y(char **str, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				map->player.pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	player_x(char **str, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				map->player.pos_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	height_map(char **map)
{
	int i;
	
	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	width_map(char **map)
{
	int len;
	
	len = ft_strlen(map[0]);
	return (len);
}

void flood_fill(char **map, int x, int y)
{
	int	width;
	int height;

	width = width_map(map);
	height = height_map(map);
	if (x < 0 || x >= width || y < 0 || y >= height)
		return;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y); // right
	flood_fill(map, x - 1, y); // left
	flood_fill(map, x, y + 1); // down
	flood_fill(map, x, y - 1); // up
}

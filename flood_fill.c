/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:14:20 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/03 20:29:31 by arimanuk         ###   ########.fr       */
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

int	height_map(char **map, t_map *map_s)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	map_s->height = i;
	return (i);
}

int	width_map(char **map, t_map *map_s)
{
	int	len;

	len = ft_strlen(map[0]);
	map_s->width = len;
	return (len);
}

void	flood_fill(char **map, t_map *map_s, int x, int y)
{
	int	width;
	int	height;

	width = map_s->width;
	height = map_s->height;
	if (x < 0 || x >= width || y < 0 || y >= height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'M')
		return ;
	map[y][x] = 'F';
	flood_fill(map, map_s, x + 1, y);
	flood_fill(map, map_s, x - 1, y);
	flood_fill(map, map_s, x, y + 1);
	flood_fill(map, map_s, x, y - 1);
}

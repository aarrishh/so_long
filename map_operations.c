/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:59:16 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/09 20:30:25 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	copy_map_part_2(char *str, char *buffer)
{
	int	i;

	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
}

char	**copy_map(char **str, t_map *map, int i)
{
	int		width;
	int		heigth;
	char	**buffer;

	buffer = NULL;
	width = width_map(str, map);
	heigth = height_map(str, map);
	buffer = (char **)malloc((heigth + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	buffer[heigth] = NULL;
	while (heigth)
	{
		buffer[i] = (char *)malloc((width + 1) * sizeof(char));
		if (!buffer[i])
		{
			free_array(buffer);
			return (NULL);
		}
		copy_map_part_2(str[i], buffer[i]);
		i++;
		heigth--;
	}
	return (buffer);
}

void	check_e_and_c_in_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				print_error("Flood Fill error\n", map);
			j++;
		}
		i++;
	}
}

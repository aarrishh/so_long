/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:12:45 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/02 20:01:50 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void check_equal_line_len(char **str)
{
	int	i;
	int	first_len;
	int second_len;

	i = 0;
	first_len = 0;
	second_len = 0;
	while (str[i + 1])
	{
		first_len = ft_strlen(str[i]);
		second_len = ft_strlen(str[i + 1]);
		if (first_len != second_len)
			print_error();
		i++;
	}
}

void	j_plus_plus(int *j, int *cur_line)
{
	(*j)++;
	(*cur_line)++;
}

void	check_valid_character(char *str, int flag, t_map *map)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '1' || str[j] == '0' 
			|| str[j] == 'M')
			j++;
		else if (str[j] == 'P')
			j_plus_plus(&j, &(map->count_P));
		else if (str[j] == 'E')
			j_plus_plus(&j, &(map->count_E));
		else if (str[j] == 'C')
			j_plus_plus(&j, &(map->count_C));
		else
			print_error();
	}
	if (flag == 1 && (map->count_E != 1 || map->count_P != 1 
		|| map->count_C < 1))
		print_error();
}


void	check_wall(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[0][j] != '\0')
	{
		if (str[0][j] != '1')
		print_error();
		j++;
	}
	while (str[i + 1])
	{
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
			print_error();
		i++;
	}
	j = 0;
	while (str[i][j])
	{
		if (str[i][j] != '1')
			print_error();
		j++;
	}
}

void	check_E_and_C_in_map(char **map)
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
				print_error();
			j++;
		}
		printf("vaxarar%s\n",map[3]);
		i++;
	}
}

void	copy_map_part_2(char *str, char *buffer)
{
	int i;

	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
}

void	free_array(char **buffer)
{
	int i;
	
	i = 0;
	while(buffer[i])
		free(buffer[i++]);
	free(buffer);
}

char	**copy_map(char **str, t_map *map)
{
	int width;
	int heigth;
	char **buffer;
	int i;

	i = 0;
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

void	check(char **str, t_map *map)
{
	int i;
	int flag;
	char **buffer;

	i = 1;
	flag = 0;
	check_equal_line_len(str);
	check_wall(str);
	while (str[i])
	{
		if (str[i + 1] == NULL)
			flag = 1;
		check_valid_character(str[i++], flag, map);
	}
	player_x(str, map);
	player_y(str, map);
	buffer = copy_map(str, map);
	if (map->player.pos_x < 0 || map->player.pos_y < 0)
	{
		fprintf(stderr, "Invalid player position\n");//poxel
		exit(1);
	}
	flood_fill(buffer, map, map->player.pos_x, map->player.pos_y);
	check_E_and_C_in_map(buffer);
	mlx(str, map);
}

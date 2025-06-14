/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:12:45 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/10 17:06:26 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	check_equal_line_len(char **str)
{
	int	i;
	int	first_len;
	int	second_len;

	i = 0;
	first_len = 0;
	second_len = 0;
	while (str[i + 1])
	{
		first_len = ft_strlen(str[i]);
		second_len = ft_strlen(str[i + 1]);
		if (first_len != second_len)
			print_error("Lines don't equal!\n", str);
		i++;
	}
}

void	j_plus_plus(int *j, int *cur_line)
{
	(*j)++;
	(*cur_line)++;
}

void	check_valid_character(char **str, int i, int flag, t_map *map)
{
	int	j;

	j = 0;
	while (str[i][j])
	{
		if (str[i][j] == '1' || str[i][j] == '0'
			|| str[i][j] == 'M')
			j++;
		else if (str[i][j] == 'P')
			j_plus_plus(&j, &(map->count_p));
		else if (str[i][j] == 'E')
			j_plus_plus(&j, &(map->count_e));
		else if (str[i][j] == 'C')
			j_plus_plus(&j, &(map->count_c));
		else
			print_error("Map contains invalid character\n", str);
	}
	if (flag == 1 && (map->count_e != 1 || map->count_p != 1
			|| map->count_c < 1))
		print_error("Invalid count of characters\n", str);
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
			print_error("Wall Error\n", str);
		j++;
	}
	while (str[i] && str[i + 1])
	{
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
			print_error("Wall Error\n", str);
		i++;
	}
	j = 0;
	while (str[i] && str[i][j])
	{
		if (str[i][j] != '1')
			print_error("Wall Error\n", str);
		j++;
	}
}

void	check(char **str, t_map *map)
{
	int		i;
	int		flag;
	char	**buffer;

	i = 1;
	flag = 0;
	check_equal_line_len(str);
	check_wall(str);
	while (str[i])
	{
		if (str[i + 1] == NULL)
			flag = 1;
		check_valid_character(str, i, flag, map);
		i++;
	}
	player_x(str, map);
	player_y(str, map);
	buffer = copy_map(str, map, 0);
	if (map->player.pos_x < 0 || map->player.pos_y < 0)
		free_when_position_negative(buffer, str);
	flood_fill(buffer, map, map->player.pos_x, map->player.pos_y);
	check_e_and_c_in_map(buffer);
	free_matrix(buffer);
	mlx(str, map);
}

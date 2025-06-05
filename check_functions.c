/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:12:45 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/05 19:19:02 by arimanuk         ###   ########.fr       */
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
			j_plus_plus(&j, &(map->count_p));
		else if (str[j] == 'E')
			j_plus_plus(&j, &(map->count_e));
		else if (str[j] == 'C')
			j_plus_plus(&j, &(map->count_c));
		else
			print_error();
	}
	if (flag == 1 && (map->count_e != 1 || map->count_p != 1
			|| map->count_c < 1))
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
		check_valid_character(str[i++], flag, map);
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

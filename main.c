/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:34:17 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/10 17:21:00 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	check_file(char *file)
{
	int	i;
	int	res;

	i = 0;
	while (file[i])
	{
		while (file[i] != '.' && file[i])
			i++;
		res = ft_strcmp((file + i), ".ber");
		if (res != 0)
		{
			write (1, "Invalid map's name!\n", 20);
			exit(1);
		}
		else
			break ;
	}
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->count_p = 0;
	map->count_e = 0;
	map->count_c = 0;
	map->player.pos_x = -1;
	map->player.pos_y = -1;
	map->player.e_pos_y = -1;
	map->player.e_pos_x = -1;
	map->key_pressed = 0;
	map->frame_count = 0;
	map->steps = 0;
}

int	main(int argc, char **argv)
{
	char		**res;
	t_map		map;

	init_map(&map);
	res = NULL;
	if (argc == 2)
	{
		check_file(argv[1]);
		res = gnl_call(argv[1]);
		if (!res || !(*res))
			print_error("Validation error\n", res);
		check(res, &map);
		free_matrix(res);
	}
	else
		return (write (2, "Error\n", 6), 1);
	return (0);
}

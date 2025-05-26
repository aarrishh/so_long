/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:10:00 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/26 21:13:14 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

typedef struct s_player{
	int pos_x;
	int pos_y;
} t_player;

typedef struct s_map{
	int width;
	int height;
	int count_E;
	int count_P;
	int count_C;
	t_player player;
} t_map;

char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_(char *s1, char *s2);
char	**gnl_call(char *str);
void	check(char **str, t_map *map);
void	print_error(void);
void	free_matrix(char **buffer);
void	flood_fill(char **map, int width, int height);
int		height_map(char **map);
int		width_map(char **map);
void	player_x(char **str, t_map *map);
void	player_y(char **str, t_map *map);

# endif
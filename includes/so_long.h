/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:10:00 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/02 20:36:44 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "../minilibx-linux/mlx.h"

#define TILE 100
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363

typedef struct s_game{
	void	*mlx;
	void	*win;
	void	*img_bg;
	void	*img_c;
	void	*img_p;
	void	*img_m;
	void	*img_w;
	void	*img_c_e;
	void	*img_o_e;
} t_game;

typedef struct s_player{
	int pos_x;
	int pos_y;
	int e_pos_x;
	int e_pos_y;
} t_player;

typedef struct s_map{
	int width;
	int height;
	int count_E;
	int count_P;
	int count_C;
	char **grid;
	t_player player;
	t_game game;
	int key_pressed;
	int frame_count;
	int steps;
} t_map;

char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_(char *s1, char *s2);
char	**gnl_call(char *str);
void	check(char **str, t_map *map);
void	print_error(void);
void	free_matrix(char **buffer);
void	flood_fill(char **map, t_map *map_s, int width, int height);
int		height_map(char **map, t_map *map_s);
int		width_map(char **map, t_map *map_s);
void	player_x(char **str, t_map *map);
void	player_y(char **str, t_map *map);
void	mlx(char **str, t_map *map);
int		handle_keypress(int keycode, t_map *map);
void	redraw(t_map *map);
char	*ft_itoa(int nbr);

# endif
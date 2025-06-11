/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:10:00 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/11 14:38:34 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define TILE 100
# define ESC 65307
# define KEY_W 16778616
# define KEY_A 16778593
# define KEY_S 16778621
# define KEY_D 16778596
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_c;
	void	*img_p;
	void	*img_m;
	void	*img_m2;
	void	*img_w;
	void	*img_bg;
	void	*img_c_e;
	void	*img_o_e;
}	t_game;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	e_pos_x;
	int	e_pos_y;
}	t_player;

typedef struct s_map
{
	int			steps;
	int			width;
	int			height;
	char		**grid;
	int			count_e;
	int			count_p;
	int			count_c;
	int			key_pressed;
	int			frame_count;
	t_player	player;
	t_game		game;
}	t_map;

// Libft Functions
char	*ft_itoa(int nbr);
int		ft_len(int n);
char	**gnl_call(char *str);
int		is_white_space(char c);
char	*ft_strjoin_(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		cal_ind(const char *s1, const char *set);
char	*ft_strtrim(char const *s1, char const *set);
int		cal_end(const char *s1, const char *set, int end, int i);

// Check And Free
void	check_new_line(char *res);
void	free_array(char **buffer);
void	free_matrix(char **buffer);
void	check(char **str, t_map *map);
void	check_e_and_c_in_map(char **map);
int		line_contain_only_white_spaces(char *str);
void	free_when_position_negative(char **buffer, char **str);
void	check_white_spaces(char **str, int i, int j, char **buffer);

// MLX
void	redraw(t_map *map);
void	game_loop(t_map *map);
void	move_player(t_map *map);
int		close_window(void *param);
void	mlx(char **str, t_map *map);
int		handle_keypress(int keycode, t_map *map);
int		handle_keyrelease(int keycode, t_map *map);

// Map And Player
void	player_x(char **str, t_map *map);
void	player_y(char **str, t_map *map);
int		width_map(char **map, t_map *map_s);
int		height_map(char **map, t_map *map_s);
char	**copy_map(char **str, t_map *map, int i);
void	flood_fill(char **map, t_map *map_s, int width, int height);

// Error
void	print_error(char *error, char **str);
#endif
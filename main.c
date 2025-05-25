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

void	j_plus_plus(int *j, int *cur_symbol)
{
	(*j)++;
	(*cur_symbol)++;
}

void	check_valid_character(char *str, int flag)
{
	static int p;
	static int e;
	static int c;
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '1' || str[j] == '0' 
			|| str[j] == 'M')
			j++;
		else if (str[j] == 'P')
			j_plus_plus(&j, &p);
		else if (str[j] == 'E')
			j_plus_plus(&j, &e);
		else if (str[j] == 'C')
			j_plus_plus(&j, &c);
		else
			print_error();
	}
	if (flag == 1 && (e != 1 || p != 1 || c < 1))
		print_error();
}


void	check_wall(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[0][j])
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

void	check(char **str)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	check_equal_line_len(str);
	check_wall(str);
	while (str[i])
	{
		if (str[i + 1] == NULL)
			flag = 1;
		check_valid_character(str[i++], flag);
	}
}

int main(int argc, char **argv)
{
	char	**res;

	res = NULL;
	if (argc == 2)
	{
		res = gnl_call(argv[1]);
		check(res);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
























// void zibilanoc(void)
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	// int		img_width = 4000;
// 	// int		img_height = 3500;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 3500, 2800, "XPM Image");
// 	int i = 0;
// 	while(i < 2)
// 	{
// 		// img = mlx_xpm_file_to_image(mlx, "images/fon.xpm", &img_width, &img_height);
// 		// if (!img)
// 		// {
// 		// 	printf("Failed to load image: images/fon.xpm\n");
// 		// 	return (1);
// 		// }
// 		// if (i == 0)
// 		// 	mlx_put_image_to_window(mlx, win, img, 0, 0);
// 		// else
// 		// 	mlx_put_image_to_window(mlx, win, img, 300, 500);

// 		// i++;
// 	}
// 	mlx_loop(mlx);
// }

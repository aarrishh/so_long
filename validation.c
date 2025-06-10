/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:09:13 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/10 17:27:11 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	**malloc_buffer(char **buffer)
{
	int	len;

	len = 0;
	while (buffer[len])
		len++;
	buffer = malloc((len + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	buffer[len] = NULL;
	return (buffer);
}

void	malloc_and_copy_char(char **str, char **buffer, int i, int j)
{
	int	index_j;

	index_j = 0;
	buffer[i] = malloc((j + 1) * sizeof(char));
	if (!buffer[i])
		return ;
	while (index_j != j)
	{
		buffer[i][index_j] = str[i][index_j];
		index_j++;
	}
	buffer[i][index_j] = '\0';
}

void	foo(char **str, char **buffer, int i)
{
	i--;
	if (buffer)
	{
		while (i >= 0)
			free(buffer[i--]);
		free(buffer);
	}
	print_error("Line contains only white spaces\n", str);
}

char	**remove_white_spaces(char **str, int i)
{
	int		j;
	char	**buffer;

	buffer = malloc_buffer(str);
	while (str[i])
	{
		if (line_contain_only_white_spaces(str[i]) == 1)
			foo(str, buffer, i);
		j = 0;
		while (str[i][j])
		{
			if (is_white_space(str[i][j]) == 1 || str[i][j] == '\0')
			{
				malloc_and_copy_char(str, buffer, i, j);
				check_white_spaces(str, i, j, buffer);
				break ;
			}
			j++;
		}
		if (str[i][j] == '\0')
			malloc_and_copy_char(str, buffer, i, j);
		i++;
	}
	free_matrix(str);
	return (buffer);
}

char	**gnl_call(char *str)
{
	int		fd;
	char	*cur_line;
	char	*res;
	char	**split;
	char	**buffer;

	buffer = NULL;
	split = NULL;
	res = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		print_error("Can not open file\n", NULL);
	cur_line = get_next_line(fd);
	while (cur_line != NULL)
	{
		res = ft_strjoin_(res, cur_line);
		free(cur_line);
		cur_line = get_next_line(fd);
	}
	free(cur_line);
	res = ft_strtrim(res, "\n\t\v\r\f ");
	check_new_line(res);
	split = ft_split(res, '\n');
	buffer = remove_white_spaces(split, 0);
	return (buffer);
}

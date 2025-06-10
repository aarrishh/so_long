/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:47:22 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/10 17:25:38 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

void	check_white_spaces(char **str, int i, int j, char **buffer)
{
	while (str[i][j] && str[i][j] != '\n')
	{
		if (is_white_space(str[i][j]) == 1)
			j++;
		else
		{
			while (i >= 0)
			{
				free(buffer[i]);
				i--;
			}
			free(buffer);
			print_error("Contain another symbols without white spaces\n", str);
		}
	}
}

int	line_contain_only_white_spaces(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (is_white_space(str[j]) == 1)
			j++;
		else
			return (0);
	}
	return (1);
}

void	free_when_position_negative(char **buffer, char **str)
{
	free_matrix(buffer);
	print_error("Negative position\n", str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:47:22 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/05 16:51:00 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_matrix(char **buffer)
{
	int	ind;

	ind = 0;
	if (buffer)
	{
		while (buffer[ind])
			free(buffer[ind++]);
		free(buffer);
		buffer = NULL;
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
	free_matrix(str);
	print_error();
}

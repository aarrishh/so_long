/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:57:56 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/09 21:23:43 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_trim(char const *s1, char const *set, int i)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == s1[i])
			return (0);
		j++;
	}
	return (-1);
}

int	check_new_line_1(char const *s1, char c, int i)
{
	while (i > 0 && s1[i] != c)
		i--;
	return (i);
}

int	cal_ind(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (check_trim(s1, set, i) == 0)
			i++;
		else if (check_trim(s1, set, i) == -1)
			return (check_new_line_1(s1, '\n', i));
	}
	return (i);
}

int	cal_end(const char *s1, const char *set, int end, int i)
{
	while (end >= i)
	{
		if (check_trim(s1, set, end) == 0)
			end--;
		else if (check_trim(s1, set, end) == -1)
			break ;
	}
	return (end);
}

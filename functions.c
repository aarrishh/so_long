/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:57:56 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/02 21:34:09 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	*ft_strjoin_(char *s1, char *s2)
{
	char	*a;
	int		i;
	int		j;
	int		s_len;
	i = 0;
	j = 0;
	
	s_len = (ft_strlen(s1) + ft_strlen(s2));
	a = (char *)malloc((s_len + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		a[i + j] = s2[j];
		j++;
	}
	a[i + j] = '\0';
	if (s1)
	free(s1);
	return (a);
}

static int	check_trim(char const *s1, char const *set, int i)
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

static int check_new_line(char const *s1, char c, int i)
{
	while (i > 0 && s1[i] != c)
		i--;
	return (i);
}

static int	cal_ind(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (check_trim(s1, set, i) == 0)
			i++;
		else if (check_trim(s1, set, i) == -1)
			return (check_new_line(s1, '\n', i));
	}
	return (i);
}

static int	cal_end(const char *s1, const char *set, int end, int i)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*a;
	int		end;
	int		malloc_i;

	if (!s1 || !set)
		return (NULL);
	i = cal_ind(s1, set);
	end = ft_strlen(s1) - 1;
	end = cal_end(s1, set, end, i);
	malloc_i = 0;
	a = (char *)malloc((end - i + 2) * sizeof(char));
	if (a == NULL)
		return (NULL);
	while (i < end + 1)
		a[malloc_i++] = s1[i++];
	a[malloc_i] = '\0';
	if (s1)
		free((char*)s1);
	return (a);
}

char *ft_strdup(char* str)
{
	int i = 0;
	char *buffer = 0;

	while (str[i])
		i++;
	buffer = (char *)malloc(i * sizeof(char));
	if (!buffer)
		return(NULL);
	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return(buffer);
}


char *ft_itoa(int nbr)
{
	int count = 1;
	int num = nbr;
	char *str = NULL;

	if (nbr == 0)
		return(ft_strdup("0"));
	if (nbr == -2147483648)
		return(ft_strdup("-2147483648"));
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr > 9)
	{
			nbr = nbr / 10;
			count++;
	}
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return(NULL);
	str[count] = '\0';
	count--;
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		nbr = num;
		if (num > 9)
			num = (num % 10);
		str[count] = num + 48;
		num = nbr / 10;
		count--;
	}
	return(str);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:51:41 by arimanuk          #+#    #+#             */
/*   Updated: 2025/06/08 19:06:24 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_array(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		free (buffer[i++]);
	free (buffer);
}

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
		free (s1);
	return (a);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = NULL;
	while (str[i])
		i++;
	buffer = (char *)malloc(i * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
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
		free ((char *)s1);
	return (a);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;
	long	long_n;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_len(n);
	arr = malloc(sizeof(char) *(len + 1));
	if (!arr)
		return (NULL);
	long_n = (long)n;
	arr[len] = '\0';
	len--;
	if (n < 0)
	{
		arr[0] = '-';
		long_n = -long_n;
	}
	while (long_n != 0)
	{
		arr[len--] = ((long_n % 10) + 48);
		long_n /= 10;
	}
	return (arr);
}

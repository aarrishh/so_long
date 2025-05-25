/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:10:00 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/24 17:39:10 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

typedef struct {
	int e;
	int p;
	int m;
	int c;
} character;

char**	gnl_call(char *str);
char	*ft_strjoin_(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	print_error(void);

# endif
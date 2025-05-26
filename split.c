#include "includes/so_long.h"

static int	getword(char const *s, char c)
{
	int	i;
	int	count_word;
	int	len;

	i = 0;
	count_word = 0;
	len = ft_strlen(s);
	while (s && s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		while (s[i] && (s[i] != c))
			i++;
		if ((s[i - 1] == c) && (i == len))
			count_word--;
		count_word++;
	}
	return (count_word);
}

static int	malloc_char(char const *s, char c, int *i, int *start)
{
	int	len;
	int	j;

	j = 0;
	len = 0;
	while (s[*i] == c)
		(*i)++;
	*start = *i;
	while (s[*i] && s[*i] != c)
	{
		len++;
		(*i)++;
	}
	return (len);
}

static char	*func_copy(char const *s, int len_current_line, int start)
{
	int		j;
	char	*line;

	j = 0;
	line = (char *)malloc((len_current_line + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (j < len_current_line)
	{
		line[j] = s[start + j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**buffer;
	int		ind;
	int		count_word;
	int		start;

	i = 0;
	ind = -1;
	count_word = getword(s, c);
	buffer = (char **)malloc((count_word + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	buffer[count_word] = NULL;
	while (count_word--)
	{
		buffer[++ind] = func_copy(s, malloc_char(s, c, &i, &start), start);
		if (!buffer[ind])
		{
			while (ind)
				free(buffer[--ind]);
			free(buffer);
			return (NULL);
		}
	}
	free((char *)s);
	return (buffer);
}

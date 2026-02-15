/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sameddah <sameddah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:07:55 by sameddah          #+#    #+#             */
/*   Updated: 2025/12/06 20:17:26 by sameddah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_caracters(char const *s, char const c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	nb_word;
	int	in_word;

	i = 0;
	nb_word = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			nb_word++;
		}
		i++;
	}
	return (nb_word);
}

static char	**free_array(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static void	ignore_sep(char const *s, char c, int *i)
{
	while (s[*i] == c)
		(*i)++;
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		pos;
	int		len;

	if (!s)
		return (NULL);
	dest = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < count_words(s, c))
	{
		ignore_sep(s, c, &pos);
		len = count_caracters(s + pos, c);
		dest[i] = ft_substr(s, pos, len);
		if (!dest[i])
			return (free_array(dest, i));
		pos += len;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
/*
int	main(void)
{
	char **result;
	int i;

	result = ft_split("Hello,this,is,a,test", ',');
	if (!result)
	{
		printf("ft_split failed\n");
		return (1);
	}

	i = 0;
	while (result[i])
	{
		printf("word[%d]: %s\n", i, result[i]);
		i++;
	}

	// Libération mémoire
	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);

	return (0);
}*/
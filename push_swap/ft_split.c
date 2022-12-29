/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:41:35 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/29 01:31:34 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wordcount(char const *s, char c)
{
	size_t		i;
	int			counter;

	counter = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c && i < ft_strlen(s))
		{
			i++;
		}
		if (s[i])
			counter += 1;
		while (s[i] != c && i < ft_strlen(s))
		{
			i++;
		}
	}
	return (counter);
}

static char	**ft_toalloc(char const *s, char c, char **split, int wordcount)
{
	size_t		i;
	int			counter;
	int			a;

	a = 0;
	i = 0;
	while (i < ft_strlen(s) && a < wordcount)
	{
		counter = 0;
		while (s[i] == c && i < ft_strlen(s))
			i++;
		while (s[i] != c && i < ft_strlen(s))
		{
			counter++;
			i++;
		}
		if (counter > 0)
		{
			split[a] = (char *)malloc(sizeof(char) * counter + 1);
			if (!split[a])
				return (0);
			a++;
		}
	}
	return (split);
}

static char	**ft_write(char const *s, char c, char **split, int wordcount)
{
	size_t	i;
	int		a;
	int		j;

	i = 0;
	a = 0;
	while (i < ft_strlen(s) && a < wordcount)
	{
		j = 0;
		while (s[i] == c && i < ft_strlen(s))
		{
			i++;
		}
		while (s[i] != c && i < ft_strlen(s))
		{
			split[a][j] = s[i];
			i++;
			j++;
		}
		if (j > 0)
			split[a][j] = '\0';
		a++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int		wordcount;
	char	**split;

	wordcount = ft_wordcount(s, c);
	if (!s)
		return (0);
	split = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!split)
		return (0);
	ft_toalloc(s, c, split, wordcount);
	ft_write(s, c, split, wordcount);
	split[wordcount] = NULL;
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:34:51 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/06 00:49:40 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return ((i + (str[i] == '\n')));
}

char	*ft_strjoin(char *stash, char *str)
{
	int			i;
	char		*line;
	int			j;

	j = 0;
	i = 0;
	//printf("String size %d, Stash Size %d", ft_strlen(str), ft_strlen(stash));
	line = (char *)malloc(ft_strlen(str) + ft_strlen(stash) + 1 * sizeof(char));
	if (!line)
		return (0);
	while (str && str[i])
	{
		line[i] = str[i];
		i++;
	}
	while (stash[j] && stash)
	{
		line[i++] = stash[j++];
		if (stash[j] == '\n')
			break ;
	}
	line[i] = 0;
	free (str);
	return (line);
}

int	ft_check(char *stash)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (stash[++i])
	{
		if (stash[i] == '\n')
		{
			stash[i++] = 0;
			j = 0;
			break ;
		}
		stash[i] = 0;
	}
	if (j == 0)
	{
		while (stash[i])
		{
			stash[j++] = stash[i];
			stash[i++] = 0;
		}
	}
	return (j);
}

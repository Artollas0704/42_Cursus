/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:34:51 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/07 09:31:13 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return ((i + (str[i] == '\n')));
}

char	*ft_strjoin(char *stash, char *str)
{
	size_t			i;
	char			*line;

	i = 0;
	line = (char *)malloc((ft_strlen(stash) + ft_strlen(str)) + 1);
	if (!line)
		return (0);
	while (str && str[i])
	{
		line[i] = str[i];
		i++;
	}
	while (*stash)
	{
		line[i++] = *stash;
		if (*stash++ == '\n')
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

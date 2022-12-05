/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:34:51 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/05 22:09:45 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i  + (str[i] == '\n'));
}

char	*ft_strjoin(char *stash, char *str)
{
	int			i;
	int			j;
	char		*line;

	i = 0;
	j = 0;

	line = (char *)malloc(ft_strlen(stash) + ft_strlen(str) + 1);
	if (!line)
		return (0);
	if (str)
	{
		while (str[i] && str)
		{
			line[i] = str[i];
			i++;
		}
		free (str);
	}
	while (stash[j] && stash)
	{
		if (stash[j] == '\n')
			break ;
		line[i++] = stash[j++];
	}
	line[i] = 0;
	return (line);
}

int	ft_check(char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			j = 0;
			break ;
		}
		stash[i] = 0;
		i++;
	}
	if (j == 0)
	{
		while (stash[j] != '\n' && stash[j] && stash[i])
		{
			stash[j++] = stash[i++];
		}
	}
	return (j);
}

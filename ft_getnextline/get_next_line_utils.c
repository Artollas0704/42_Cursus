/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:34:51 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/02 20:08:42 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_nextline(char *stash)
{
	char	*str;
	int		linelen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	linelen = ft_strlen(stash);
	str = (char *)malloc(linelen + 1);
	if (!str)
		return (0);
	while (j < linelen)
	{
		str[i++] = stash[j++];
	}
	str[i] = '\0';
	//stash += j;
	return (str);
}
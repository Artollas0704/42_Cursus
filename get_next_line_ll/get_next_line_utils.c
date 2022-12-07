/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:09:09 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/07 16:37:37 by aalves-p         ###   ########.fr       */
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
	return (i + (str[i] == '\n'));
}

char	*next_line(t_list *stash, t_lista *str)
{
	int		i;
	int 	j;

	j = 0;
	i = 0;
		printf("Value of line inside %s\n", str->line);

	str->temp = malloc(ft_strlen(stash->stash) + ft_strlen(str->line) + 1);
	while (str->line && str->line[i])
	{
		str->temp[i] = str->line[i];
		printf("str to temp %s\n", str->temp);
		i++;
	}
	while (stash->stash[j])
	{
		str->temp[i++] = stash->stash[j];
		if (stash->stash[j++] == '\n')
			break ;
	}
	str->temp[i] = 0;
	free (str->line);
	printf("Temp %s\n", str->temp);
	return (str->temp);
}

int	check(t_list **stash)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while ((*stash)->stash[++i])
	{
		printf("Stash being cleared %c\n", (*stash)->stash[i]);
		if ((*stash)->stash[i] == '\n')
		{
			(*stash)->stash[i++] = 0;
			j = 0;
			break ;
		}
		(*stash)->stash[i] = 0;
	}
	if (j == 0)
	{
		while ((*stash)->stash[i])
		{
			(*stash)->stash[j++] = (*stash)->stash[i];
			(*stash)->stash[i++] = 0;
		}
	}
	printf("Stash rewrite %s\n", (*stash)->stash);
	return (j);
}


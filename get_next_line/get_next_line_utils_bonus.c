/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:27:09 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/25 17:17:58 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (*s && s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *str, char *buffer)
{
	int		i;
	char	*str_ret;

	i = 0;
	str_ret = (char *)malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
	if (!str_ret)
		return (0);
	while (str && str[i])
	{
		str_ret[i] = str[i];
		i++;
	}
	while (*buffer)
	{
		str_ret[i++] = *buffer;
		if (*buffer++ == '\n')
			break ;
	}
	str_ret[i] = 0;
	free (str);
	return (str_ret);
}

int	ft_checkn(char *buffer, int i)
{
	char	*temp;
	char	*buffer_copy;

	buffer_copy = buffer;
	temp = buffer;
	while (*buffer_copy)
	{
		if (*buffer_copy == '\n')
		{
			i = 1;
			*buffer_copy++ = 0;
			break ;
		}
		*buffer_copy++ = 0;
	}
	if (i == 1)
	{
		while (*buffer_copy)
		{
			*temp++ = *buffer_copy;
			*buffer_copy++ = 0;
		}
	}
	return (i);
}

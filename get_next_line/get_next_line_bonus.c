/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:26:28 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/25 17:20:21 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = 0;
	str = 0;
	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	while (*buffer[fd] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer[fd]);
		if (ft_checkn(buffer[fd], i))
			break ;
	}
	return (str);
}

/* int main()
{
	int fd = open("file", O_RDONLY);
	char	*str;
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);
} */
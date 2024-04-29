/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:26:28 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/28 17:35:57 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = 0;
	str = 0;
	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (ft_checkn(buffer, i))
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
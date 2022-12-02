/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:35:12 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/02 20:11:01 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Create static var for buffersize + 1 for NULL
//Create string which will have all the Lines
//Make Condition for -1 on read and if BUFFER is smaller than 1
//Initialize string as NULL
//Send string to join if my stash is not 0 first position and my read is > 0
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*str;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
		return (0);
	str = NULL;
	if (read(fd, stash, BUFFER_SIZE) > 0 && stash[0] != '\0')
	{
		str = ft_nextline(stash);
		if (str[0] != '\0')
			get_next_line(fd);
	}
	return (str);
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	printf("fd Value %d\n", fd);
	char *str = get_next_line(fd);
	printf("Read this %s", str);
}

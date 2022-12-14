/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:35:12 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/14 09:34:54 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Create static var for buffersize + 1 for NULL
//Create string which will have all the Lines
//Make Condition for -1 on read and if BUFFER is smaller than 1
//Initialize string reate static var for buffersize + 1 for NULL
//Create string which will have all the Lines
//Make Condition for -1 onas NULL
//Send string to join if my stash is not 0 first position and my read is > 0
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = -1;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (stash[++i])
			stash[i] = 0;
		return (0);
	}
	str = NULL;
	while (*stash || read(fd, stash, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(stash, str);
		if (ft_check(stash) >= 0)
			break ;
	}
	return (str);
}

/* int main()
{
	int fd = open("file.txt", O_RDONLY);
	printf("fd Value %d\n", fd);
	char *str1 = get_next_line(fd);
	char *str2 = get_next_line(fd);
	char *str3 = get_next_line(fd);
	printf("Read this %s\n", str1);
	printf("Read this %s\n", str2);
	printf("Read this %s\n", str3);
}
 */
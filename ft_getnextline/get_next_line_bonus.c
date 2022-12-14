/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:35:12 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/14 09:46:12 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Create static var for buffersize + 1 for NULL
//Create string which will have all the Lines
//Make Condition for -1 on read and if BUFFER is smaller than 1
//Initialize string reate static var for buffersize + 1 for NULL
//Create string which will have all the Lines
//Make Condition for -1 onas NULL
//Send string to join if my stash is not 0 first position and my read is > 0
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = -1;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (fd > 0 && fd < FOPEN_MAX)
		{
			while (stash[fd][++i])
			stash[fd][i] = 0;
		}
		return (0);
	}
	str = NULL;
	while (*stash[fd] || read(fd, stash[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(stash[fd], str);
		if (ft_check(stash[fd]) >= 0)
			break ;
	}
	return (str);
}

/* int main()
{
	int fd = open("file.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	char *str1 = get_next_line(fd);
	char *str2 = get_next_line(fd2);
	char *str3 = get_next_line(fd);
	printf("Read this %s\n", str1);
	printf("Read this %s\n", str2);
	printf("Read this %s\n", str3);
} */

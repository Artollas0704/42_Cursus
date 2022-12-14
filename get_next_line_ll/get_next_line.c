/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:48:47 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/14 11:18:36 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;

	if (!stash)
		stash = (t_list *)malloc(sizeof(t_list));
	stash->line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	while (*stash->stash || read(fd, stash->stash, BUFFER_SIZE) > 0)
	{
		stash->line = next_line(stash, stash);
		if (check(&stash) >= 0)
			break ;
	}
	free(stash->temp);
	return (stash->line);
}

/* int	main()
{
	int		fd;
	fd = open("file.txt", O_RDONLY);
	printf("First Line %s", get_next_line(fd));
	printf("Second Line %s", get_next_line(fd));
	printf("Theree Line %s", get_next_line(fd));
	close(fd);
}
 */
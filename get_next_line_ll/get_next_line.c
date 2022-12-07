/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:48:47 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/07 16:47:33 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list *stash;
	t_lista			*line;

	stash = (t_list *)malloc(sizeof(t_list));
	line = (t_lista *)malloc(sizeof(t_lista));
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		return (NULL);
	}
	line->line = NULL;
		printf("Check Stash %s\n", stash->stash);
	while (*stash->stash || read(fd, stash->stash, BUFFER_SIZE) > 0)
	{
		line->line = next_line(stash, line);
		if (check(&stash) >= 0)
			break ;
		printf("Value of line %s\n", line->line);
		//cleartemp(line);
		//printf("Check Stash %s\n", stash->stash);
	}
	//printf("line %s\n", line->line);
	return (line->line);
}

int	main()
{
	int		fd;
	fd = open("file.txt", O_RDONLY);
	printf("First Line %s", get_next_line(fd));
	printf("Second Line %s", get_next_line(fd));
	printf("Theree Line %s", get_next_line(fd));
	close(fd);
}

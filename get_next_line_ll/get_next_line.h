/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:47:20 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/07 12:13:54 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

typedef struct s_list
{
	char	*stash;
}		t_list;

typedef struct s_lista
{
	char	*line;
	char	*temp;
}		t_lista;

void	next_line(t_list **stash, t_lista **str);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		check(t_list **stash);
#endif
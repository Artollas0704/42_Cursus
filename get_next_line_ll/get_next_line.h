/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:47:20 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/14 11:17:08 by aalves-p         ###   ########.fr       */
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
#  define BUFFER_SIZE 5

# endif

typedef struct s_list
{
	char	stash[BUFFER_SIZE + 1];
	char	*line;
	char	*temp;
}		t_list;

char	*next_line(t_list *stash, t_list *str);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		check(t_list **stash);
void	cleartemp(t_list *temp);
#endif
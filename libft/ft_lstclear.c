/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:00:46 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/09 16:30:02 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!(*lst))
		return ;
	while ((*lst) != NULL)
	{
		temp = *lst;
		del((*lst)->content);
		(*lst) = (*lst)->next;
		free((temp));
	}
	(*lst) = NULL;
}

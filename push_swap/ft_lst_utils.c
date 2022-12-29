/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:51:49 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/29 10:31:30 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	temp = ft_lstlast(temp);
	temp->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!last)
		return (0);
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
	{
		*lst = new;
	}
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
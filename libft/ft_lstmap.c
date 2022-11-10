/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:36:09 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/09 17:18:48 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*slst;
	t_list	*storage;

	slst = 0;
	while (lst != NULL)
	{
		storage = ft_lstnew(f(lst->content));
		if (!storage)
		{
			del(slst->content);
			return (0);
		}
		ft_lstadd_back(&slst, storage);
		lst = lst->next;
	}
	return (slst);
}

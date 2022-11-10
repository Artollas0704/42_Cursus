/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:37:50 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/02 16:40:53 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		while (big[i + j] == little[j] && i + j < len
			&& big[i + j] && little[j])
		{
			j++;
		}
		if (j == ft_strlen(little))
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (0);
}

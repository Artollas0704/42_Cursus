/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:29:09 by aalves-p          #+#    #+#             */
/*   Updated: 2022/10/31 18:42:34 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		toalloc;
	char		*concat;
	size_t		i;
	size_t		b;

	i = 0;
	b = 0;
	toalloc = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s1 || !s2)
		return (0);
	concat = (char *)malloc(toalloc);
	if (!concat)
		return (0);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		concat[i + b] = s2[b];
		b++;
	}
	concat[i + b] = '\0';
	return (concat);
}

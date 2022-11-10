/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:41:17 by aalves-p          #+#    #+#             */
/*   Updated: 2022/10/31 17:58:53 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ptr;

	size = ft_strlen(s) +1;
	ptr = (char *)malloc(size);
	if (!ptr)
		return (0);
	ft_memcpy (ptr, s, size);
	return (ptr);
}

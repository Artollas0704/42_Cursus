/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:27:42 by aalves-p          #+#    #+#             */
/*   Updated: 2022/10/31 10:55:35 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	a;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	a = dest_len;
	i = 0;
	if (dest_len >= size || size == 0)
	{
		dest_len = size;
	}
	if (dest_len < size - 1 && size > 0)
	{
		while (src[i] && dest_len + i < size -1)
		{
			dst[a++] = src[i++];
		}
		dst[a] = 0;
	}
	return (dest_len + src_len);
}

/*int main()
{
	char dest[] = "Hello ";
	char src[] = "World!";
	
	printf("%ld\n", ft_strlcat(dest,src,10));
	printf("%s", dest);
}*/
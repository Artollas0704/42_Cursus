/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:06:57 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/09 17:17:58 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	end;
	size_t	i;

	i = 0;
	end = 0;
	if (start < ft_strlen(s))
		end = ft_strlen(s) - start;
	if (end > len)
		end = len;
	substr = (char *)malloc(sizeof(char) * (end + 1));
	if (!substr)
		return (0);
	while (start < ft_strlen(s) && i < end)
	{
		substr[i++] = s[start++];
	}
	substr[i] = 0;
	return (substr);
}

/* int main()
{
	printf("%s", ft_substr("hola", 4294967295, 0));
} */

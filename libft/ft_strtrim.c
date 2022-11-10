/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:38:26 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/09 13:55:59 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	len;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1);
	while (len > start && ft_strchr(set, s1[len -1]))
		len--;
	str = (char *)malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < len)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

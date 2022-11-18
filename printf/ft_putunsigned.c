/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:56:48 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/18 00:38:35 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_writenumb(char *ptr, unsigned int nb, int counter)
{
	ptr[counter] = '\0';
	counter -= 1;
	while (nb > 0)
	{
		ptr[counter] = nb % 10 + 48;
		nb = nb / 10;
		counter--;
	}
	return (ptr);
}

static int	ft_toalloc(unsigned int n)
{
	int	counter;

	counter = 0;
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static char	*ft_itoaun(unsigned int n)
{
	unsigned int		toalloc;
	char				*ptr;

	toalloc = ft_toalloc(n);
	if (n == 0)
	{
		ptr = (char *)malloc(sizeof(char) + 1);
		if (!ptr)
			return (0);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	ptr = (char *)malloc(sizeof(char) * (toalloc + 1));
	if (!ptr)
		return (0);
	return (ft_writenumb(ptr, n, toalloc));
}

int	ft_putunsigned(unsigned int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoaun(nb);
	len = ft_putstr(str);
	free(str);
	return (len);
}

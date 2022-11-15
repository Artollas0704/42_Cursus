/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:39:18 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/15 19:10:20 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_writenumb(char *ptr, long nb, int counter)
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

static int	ft_toalloc(long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter += 1;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		toalloc;
	char	*ptr;
	long	nb;

	nb = n;
	toalloc = ft_toalloc(nb);
	if (nb == 0)
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
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = nb * -1;
	}
	return (ft_writenumb(ptr, nb, toalloc));
}

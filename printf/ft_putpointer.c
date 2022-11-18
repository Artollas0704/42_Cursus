/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:59:39 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/18 00:38:25 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_puthexaun(unsigned long int nb, char *hexa)
{
	int	counter;

	counter = 0;
	if (nb >= 16)
		counter += ft_puthexaun(nb / 16, hexa);
	counter += ft_putchar(hexa[nb % 16]);
	return (counter);
}

int	ft_putpointer(unsigned long int ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_puthexaun(ptr, "0123456789abcdef");
	return (len);
}

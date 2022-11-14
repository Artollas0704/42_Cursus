/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:19:46 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/14 17:44:53 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*ft_alloc(char lowup)
{
	char	*hexa;

	if (lowup == 'x')
	{
		hexa = (char *)malloc(sizeof(char) * 17);
		if (!hexa)
			return (0);
		hexa = "0123456789abcdef";
		return (hexa);
	}
	else if (lowup == 'X')
	{
		hexa = (char *)malloc(sizeof(char) * 17);
		if (!hexa)
			return (0);
		hexa = "0123456789ABCDEF";
		return (hexa);
	}
	return (0);
}

int	ft_puthexa(unsigned int nb, char lowup)
{
	char	*hexa;
	int		len;

	len = 0;
	hexa = ft_alloc(lowup);
	if (nb < 16)
		len += ft_putchar(hexa[nb]);
	if (nb >= 16)
	{
		ft_puthexa (nb / 16, lowup);
		ft_puthexa (nb % 16, lowup);
	}
	return (len);
}
//free(hexa)? error?

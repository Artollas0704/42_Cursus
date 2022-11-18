/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:19:46 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/18 00:38:19 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int nb, char *hexa)
{
	int	counter;

	counter = 0;
	if (nb >= 16)
		counter += ft_puthexa(nb / 16, hexa);
	counter += ft_putchar(hexa[nb % 16]);
	return (counter);
}

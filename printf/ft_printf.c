/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:42:14 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/14 16:58:51 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_print(va_list args, int toprint)
{
	int	len;

	len = 0;
	if (toprint == 'c')
		len += ft_putchar(va_arg(args, int));
	if (toprint == 's')
		len += ft_putstr(va_arg(args, char *));
	if (toprint == 'd' || toprint == 'i')
		len += ft_printnb(va_arg(args, int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_print(args, str[i + 1]);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

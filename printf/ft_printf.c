/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:42:14 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/15 19:27:26 by aalves-p         ###   ########.fr       */
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
	else if (toprint == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (toprint == 'd' || toprint == 'i')
		len += ft_printnb(va_arg(args, int));
	else if (toprint == '%')
		len += ft_putchar('%');
	else if (toprint == 'x' || toprint == 'X')
	{
		if (toprint == 'x')
			len += ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef");
		else if (toprint == 'X')
			len += ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	}
	else if (toprint == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
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
			len += ft_print(args, str[++i]);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}


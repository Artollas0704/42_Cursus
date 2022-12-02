/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:42:14 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/18 18:14:53 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_print(va_list args, int toprint)
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
	else if (toprint == 'p')
		len += ft_putpointer(va_arg(args, unsigned long int));
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

int main()
{
	/* int res;
	res =0; */
	//printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("%u\n", -245);
	ft_printf("%u\n", -245);
	/* res = ft_printf("Numero minha funcao %p\n", "Hello");
	ft_printf("Numero caracteres %d\n", res); */
}

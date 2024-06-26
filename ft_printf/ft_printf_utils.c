/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:12:44 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/27 12:27:04 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putunbr(unsigned int n, t_flags *flags)
{
	int		i;

	i = 0;
	if (flags->numberu == 0)
		flags->numberu = n;
	if (flags->minimum_width)
		i += ft_printflags_unsigned_hexa(n, flags);
	if (flags->zero_padding != 0 || flags->precision != 0)
		i += ft_printflags_unsigned_hexa(n, flags);
	if (n > 9)
		i += ft_putunbr(n / 10, flags);
	i += ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_putnbr(int n, t_flags *flags)
{
	int		i;
	long	num;

	num = n;
	if ((flags->left && flags->numberdi == 0) || flags->minimum_width)
	{
		flags->numberdi = num;
		flags->di = 1;
	}
	i = 0;
	if (flags->minimum_width)
		i += ft_printflags_putnbr(n, flags);
	i += ft_checkplusminus(num, flags, n);
	if (num < 0)
	{
		i += ft_putchar('-');
		num *= -1;
	}
	if (flags->zero_padding != 0 || flags->precision != 0)
		i += ft_printflags_putnbr(n, flags);
	if (num > 9)
		i += ft_putnbr(num / 10, flags);
	i += ft_putchar(num % 10 + '0');
	return (i);
}

int	ft_check(const char *s, va_list args, t_flags *flags)
{
	int	i;

	i = 0;
	if (*s == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*s == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (*s == 'd' || *s == 'i')
		i += ft_putnbr(va_arg(args, int), flags);
	else if (*s == 'u')
		i += ft_putunbr(va_arg(args, unsigned int), flags);
	else if (*s == 'x')
		i += ft_puthex(va_arg(args, unsigned int), 0, flags->hexa, flags);
	else if (*s == 'X')
		i += ft_puthex(va_arg(args, unsigned int), 1, flags->hexa, flags);
	else if (*s == 'p')
		i += ft_putptr(va_arg(args, unsigned long), flags);
	else if (*s == '%')
		i += ft_putchar('%');
	return (i);
}

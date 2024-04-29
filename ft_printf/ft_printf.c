/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:09:29 by aralves-          #+#    #+#             */
/*   Updated: 2024/04/28 18:30:14 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	init_flags(t_flags *flags)
{
	flags->plus_sign = 0;
	flags->space_before_positive = 0;
	flags->hexa = 0;
	flags->minimum_width = 0;
	flags->precision = 0;
	flags->zero_padding = 0;
	flags->left = 0;
	flags->size = 0;
	flags->numberdi = 0;
	flags->numberxp = 0;
	flags->numberu = 0;
	flags->di = 0;
	flags->xp = 0;
	flags->u = 0;
}

int	ft_puthex(unsigned long n, int value, int flag, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->minimum_width)
		i += ft_printflags_putnbr(n, flags);
	if (flag == 1 && value == 0 && n > 0)
		i += ft_putstr("0x");
	if (flag == 1 && value == 1 && n > 0)
		i += ft_putstr("0X");
	if (n > 15)
		i += ft_puthex(n / 16, value, 0, flags);
	if (n % 16 < 10)
		i += ft_putchar(n % 16 + '0');
	else if (value == 0)
		i += ft_putchar(n % 16 - 10 + 'a');
	else
		i += ft_putchar(n % 16 - 10 + 'A');
	return (i);
}

int	ft_putptr(unsigned long n, t_flags *flags)
{
	int	i;

	i = 0;
	if (!n)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	i += ft_putstr("0x");
	i += ft_puthex(n, 0, 0, flags);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	t_flags	flags;

	i = 0;
	va_start(args, s);
	while (*s)
	{
		init_flags(&flags);
		if (*s == '%')
		{
			s++;
			s += ft_check_bonus((char *)s, &flags, args);
			i += ft_check(s, args, &flags);
			i += ft_left_justify(&flags);
		}
		else
			i += ft_putchar(*s);
		s++;
	}
	return (i);
}

/* int	main(void)
{
	//ft_printf("% -.*d\n", 3, 11);
	//printf("OG Printf: %-2.4x \n", 12);
	//printf("%d", ft_atoi("12"));
} */
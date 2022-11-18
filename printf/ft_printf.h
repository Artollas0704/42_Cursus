/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:19:38 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/18 00:39:41 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_printnb(int nb);
int		ft_puthexa(unsigned int nb, char *hexa);
int		ft_putunsigned(unsigned int nb);
int		ft_putpointer(unsigned long	int ptr);
char	*ft_itoa(int n);
#endif
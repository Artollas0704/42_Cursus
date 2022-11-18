/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:52:55 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/18 00:36:37 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str == NULL)
	{
		len = ft_putstr("(null)");
		return (len);
	}
	while (str[i])
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

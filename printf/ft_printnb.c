/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:53:37 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/18 00:40:21 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnb(int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(nb);
	len = ft_putstr(str);
	free(str);
	return (len);
}

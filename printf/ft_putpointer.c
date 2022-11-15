/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:59:39 by aalves-p          #+#    #+#             */
/*   Updated: 2022/11/15 19:04:37 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

int	ft_putpointer(void	*ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	len = ft_puthexa((unsigned int)ptr, "0123456789abcdef");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:26:12 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/29 10:32:46 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(char **args)
{
	int	a;
	int	check;
	int	num;
	int	j;
	int	first;

	first = 1;
	j = 0;
	a = 0;
	while (args[a])
	{
		num = ft_atoi(args[a]);
		while (args[j])
		{
			check = ft_atoi(args[j]);
			if (check == num && first == 0 && j != a)
				return (0);
			first = 0;
			j++;
		}
		j = 0;
		first = 1;
		a++;
	}
	return (1);
}

int	arr_valid(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	check_numbers(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && str[i] != '+'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check(char **args, t_list **stack)
{
	int		a;
	t_list	*tmp;

	a = 0;
	tmp = NULL;
	while (args[a])
	{
		if (!check_dups(args) || !check_numbers(args[a])
			|| !arr_valid(ft_atoi(args[a])))
			return (0);
		tmp = ft_lstnew(ft_atoi(args[a]));
		ft_lstadd_back(stack, tmp);
		free(tmp);
		a++;
	}
	//free(tmp);
	return (1);
}

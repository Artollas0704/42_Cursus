/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalves-p <aalves-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:12:23 by aalves-p          #+#    #+#             */
/*   Updated: 2022/12/29 09:54:14 by aalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	write_list(t_list *stack)
{
	while (stack)
	{
		printf("Test%d\n", stack->content);
		stack = stack->next;
	}
} */

int	main(int ac, char **av)
{
	char	**args;
	t_list	*stack_a;
	//t_list	*stack_b;
	int		i;

	i = 0;
	stack_a = NULL;
	//stack_b = NULL;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!ft_check(args, &stack_a) || !args[0])
			write(1, "Error\n", 6);
		while (args[i])
			free(args[i++]);
		free(args);
		//write_list(stack_a);
	}
	else if (ac > 2)
		write(1, "Error\n", 6);
	return (0);
}

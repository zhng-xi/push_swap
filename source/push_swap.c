/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:04:09 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 19:51:33 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack **stack) //->delete later
{
	t_stack	*print;

	print = *stack;
	while (print)
	{
		ft_printf("%d *** ", print->nb);
		print = print->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac < 2)
		error();
	stack_a = fill_stack(ac, av);
	get_order(&stack_a);
	if (check_double(&stack_a))
	{
		free_stack(&stack_a);
		error();
	}
	if (!check_sorted(stack_a))
		sort(&stack_a);
	free_stack(&stack_a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:34:19 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 14:03:43 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (find_last(*stack_a)->nb == get_max(*stack_a))
		sa(stack_a, 0);
	else if (find_last(*stack_a)->nb == get_min(*stack_a))
	{
		sa(stack_a, 0);
		rra(stack_a, 0);
	}
	else if (get_min(*stack_a) == (*stack_a)->nb)
	{
		ra(stack_a, 0);
		if (!check_sorted(*stack_a))
		{
			sa(stack_a, 0);
			rra(stack_a, 0);
		}
	}
	else if (get_max(*stack_a) == (*stack_a)->nb)
		ra(stack_a, 0);
}

void	start_b(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) == 4)
		pb(stack_a, stack_b, 0);
	else if (stack_size(*stack_a) == 5)
	{
		pb(stack_a, stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	
}

t_stack	**push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	do_steps_ba(stack_a, stack_b);
	return (stack_a);
}

t_stack	*push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b) == NULL)
		start_b(stack_a, stack_b);
	if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	else if (stack_size(*stack_a) > 3)
		do_steps_ab(stack_a, stack_b);
	return (*stack_b);
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	long	size;

	stack_b = NULL;
	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a, 0);
	else if (size == 3)
		sort_three(stack_a);
	else
	{
		stack_b = push_to_b(stack_a, &stack_b);
		stack_a = push_to_a(stack_a, &stack_b);
	}
}

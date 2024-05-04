/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:58:40 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 21:26:59 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_rarb(t_stack **stack_a, t_stack **stack_b, int b, int a)
{
	while((*stack_b)->nb != b && find_index(*stack_a, a) > 0)
		rr(stack_a, stack_b, 0);
	while ((*stack_b)->nb != b)
		rb(stack_b, 0);
	while (find_index(*stack_a, a) > 0)
		ra(stack_a, 0);
	if (!(find_index(*stack_b, (*stack_b)->nb) == 0))
		rb(stack_a, 0);
	pa(stack_a, stack_b, 0);
}

void	b_rrarrb(t_stack **stack_a, t_stack **stack_b, int b, int a)
{
	while((*stack_b)->nb != b && find_index(*stack_a, a) >= 0)
		rrr(stack_a, stack_b, 0);
	while ((*stack_b)->nb != b)
		rrb(stack_b, 0);
	while (find_index(*stack_a, a) >= 0)
		rra(stack_a, 0);
	if (!(find_index(*stack_b, (*stack_b)->nb) == 0))
		rrb(stack_b, 0);
	pa(stack_a, stack_b, 0);
}

void	do_steps_ba(t_stack **stack_a, t_stack **stack_b)
{
	int		best;
	int		size;
	int		i;

	size = stack_size(*stack_b);
	if (size == 1)
	{
		get_steps_ba(stack_a, stack_b);
		//(*stack_b)->match = find_match_ba(stack_a, stack_b);
		best = perfect_match(*stack_b);
		i = find_index(*stack_a, (*stack_b)->match);
		while (i > 0)
		{
			ra(stack_a, 0);
			i--;
		}
		pa(stack_a, stack_b, 0);
	}
	while (size-- >= 0)
	{
		get_steps_ba(stack_a, stack_b);
		best = perfect_match(*stack_b);
		if ((best == get_steps_ba(stack_a, stack_b))
			&& (*stack_b)->upper == true
			&& (find_index(*stack_a, (*stack_b)->match) < get_mid(*stack_a)))
		{
			b_rarb(stack_a, stack_b, (*stack_b)->nb, (*stack_b)->match);
		}
		else if ((best == get_steps_ba(stack_a, stack_b))
			&& (*stack_b)->upper == false
			&& (find_index(*stack_a, (*stack_b)->match) < get_mid(*stack_a)))
			b_rrarrb(stack_a, stack_b, (*stack_b)->nb, (*stack_b)->match);
	}
}

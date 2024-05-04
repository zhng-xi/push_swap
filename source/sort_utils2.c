/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:50:50 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 20:41:44 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_steps_ab(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_b);
	(*stack_a)->steps = find_index(*stack_b, find_match_ab(stack_a, stack_b));
	if ((*stack_a)->steps < calc_a(stack_a))
		(*stack_a)->steps = calc_a(stack_a);
	return ((*stack_a)->steps);
}

int	get_steps_ba(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	(*stack_b)->steps = find_index(*stack_a, find_match_ba(stack_a, stack_b));
	if ((*stack_b)->steps < calc_b(stack_b))
		(*stack_b)->steps = calc_b(stack_b);
	return ((*stack_b)->steps);
}

int	perfect_match(t_stack *stack)
{
	t_stack	*tmp;
	int		best;

	tmp = stack;
	best = tmp->steps;
	while (tmp)
	{
		if (tmp->steps < best)
			best = tmp->steps;
		tmp = tmp->next;
	}
	return (best);
}

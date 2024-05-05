/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:50:50 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/05 13:10:28 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_calc(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		size;
	int		size2;

	tmp = (*stack_a);
	tmp2 = (*stack_b);
	size = stack_size(*stack_a);
	size2 = stack_size(*stack_b);
	while (tmp)
	{
		calc_a(&tmp, size);
		tmp = tmp->next;
	}
	while (tmp2)
	{
		calc_b(&tmp2, size2);
		tmp2 = tmp2->next;
	}
}

void	get_steps_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	get_calc(stack_a, stack_b);
	tmp = (*stack_a);
	while (tmp)
	{
		(*stack_a)->steps = find_index(*stack_b, (*stack_a)->match_a) - 1;
		if ((*stack_a)->steps < (*stack_a)->cost)
			(*stack_a)->steps = (*stack_a)->cost;
		tmp = tmp->next;
	}
}

void	get_steps_ba(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	get_calc(stack_a, stack_b);
	tmp = (*stack_b);
	while (tmp)
	{
		(*stack_b)->steps = find_index(*stack_a, (*stack_b)->match_b);
		if ((*stack_b)->steps < (*stack_b)->cost)
			(*stack_b)->steps = (*stack_b)->cost;
		tmp = tmp->next;
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:49:41 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 17:42:40 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calc_a(t_stack **stack_a)
{
	int	size;
	int	len;

	size = stack_size(*stack_a);
	len = get_mid(*stack_a);
	if (find_index(*stack_a, (*stack_a)->nb) < len)
	{
		(*stack_a)->cost = find_index(*stack_a, (*stack_a)->nb);
		(*stack_a)->upper = true;
	}
	else
	{
		(*stack_a)->cost = size - find_index(*stack_a, (*stack_a)->nb);
		(*stack_a)->upper = false;
	}
	return ((*stack_a)->cost);
}

int	calc_b(t_stack **stack_b)
{
	int	size;
	int	len;

	size = stack_size(*stack_b);
	len = get_mid(*stack_b);
	if (find_index(*stack_b, (*stack_b)->nb) < len)
	{
		(*stack_b)->cost = find_index(*stack_b, (*stack_b)->nb);
		(*stack_b)->upper = true;
	}
	else
	{
		(*stack_b)->cost = size - find_index(*stack_b, (*stack_b)->nb);
		(*stack_b)->upper = false;
	}
	return ((*stack_b)->cost);
}

int	find_match_ab(t_stack **stack_a, t_stack **stack_b)
{
	int		match;

	match = (*stack_a)->nb;
	while ((*stack_b)->nb != match)
	{
		if (find_index(*stack_b, match))
			(*stack_a)->match = match;
		match++;
	}
	return ((*stack_a)->match);
}

int	find_match_ba(t_stack **stack_a, t_stack **stack_b)
{
	int	match;
	t_stack	*tmp;

	match = 0;
	get_order(stack_a);
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->nb < (*stack_b)->nb)
		{
			
		}
		tmp = tmp->next;
	}
	return ((*stack_b)->match);
}

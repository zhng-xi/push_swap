/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:58:40 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/05 13:10:19 by xzheng           ###   ########.fr       */
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
	while((*stack_b)->nb != b && find_index(*stack_a, a) > 0)
		rrr(stack_a, stack_b, 0);
	while ((*stack_b)->nb != b)
		rrb(stack_b, 0);
	while (find_index(*stack_a, a) > 0)
		rra(stack_a, 0);
	if (!(find_index(*stack_b, (*stack_b)->nb) == 0))
		rrb(stack_b, 0);
	pa(stack_a, stack_b, 0);
}

void	b_rrarb(t_stack **stack_a, t_stack **stack_b, int b, int a)
{
	while ((*stack_b)->nb != b && find_index(*stack_a, a) > 0)
	{
		rb(stack_b, 0);
		rra(stack_a, 0);
	}
	while ((*stack_b)->nb != b)
		rb(stack_b, 0);
	while (find_index(*stack_a, a) > 0)
		rra(stack_a, 0);
	pa(stack_a, stack_b, 0);
}

void	b_rarrb(t_stack **stack_a, t_stack **stack_b, int b, int a)
{
	while ((*stack_a)->nb != a && find_index(*stack_b, b) > 0)
	{
		rrb(stack_b, 0);
		ra(stack_a, 0);
	}
	while ((*stack_b)->nb != b)
		rrb(stack_b, 0);
	while (find_index(*stack_a, a) > 0)
		ra(stack_a, 0);
	pa(stack_a, stack_b, 0);
}

void	only_one(t_stack **stack_a, t_stack **stack_b)
{
	int	best;
	int	i;
	int	len;
	
	get_steps_ba(stack_a, stack_b);
	best = perfect_match(*stack_b);
	i = find_index(*stack_a, (*stack_b)->match_b);
	len = get_mid(*stack_a);
	if (i < len)
	{
		while (i-- > 0)
			ra(stack_a, 0);
	}
	else
	{
		while (i-- > 0)
			rra(stack_a, 0);
	}
	pa(stack_a, stack_b, 0);
}

void	do_steps_ba(t_stack **stack_a, t_stack **stack_b)
{
	int		best;
	int		size;


	size = stack_size(*stack_b);
	if (size == 1)
		only_one(stack_a, stack_b);
	set_index(stack_b, size);
	set_index(stack_a, stack_size(*stack_a));
	get_steps_ba(stack_a, stack_b);
	best = perfect_match(*stack_b);
	if (best == (*stack_b)->steps && (*stack_b)->upper == true
		&& (find_index(*stack_a, (*stack_b)->match_b) < get_mid(*stack_a)))
		b_rarb(stack_a, stack_b, (*stack_b)->nb, (*stack_b)->match_b);
	else if (best == (*stack_b)->steps && (*stack_b)->upper == false
		&& (find_index(*stack_a, (*stack_b)->match_b) > get_mid(*stack_a)))
		b_rrarrb(stack_a, stack_b, (*stack_b)->nb, (*stack_b)->match_b);
	else if (best == (*stack_b)->steps && (*stack_b)->upper == true
		&& (find_index(*stack_a, (*stack_b)->match_b) > get_mid(*stack_a)))
		b_rarrb(stack_a, stack_b, (*stack_b)->nb, (*stack_b)->match_b);
	else if (best == (*stack_b)->steps && (*stack_b)->upper == false
		&& (find_index(*stack_a, (*stack_b)->match_b) < get_mid(*stack_a)))
		b_rrarb(stack_a, stack_b, (*stack_b)->nb, (*stack_b)->match_b);
}

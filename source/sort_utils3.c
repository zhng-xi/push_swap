/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:34:08 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/05 13:10:41 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_rarb(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	while((*stack_a)->nb != a && find_index(*stack_b, b) > 0)
		rr(stack_a, stack_b, 0);
	while ((*stack_a)->nb != a)
		ra(stack_a, 0);
	while (find_index(*stack_b, b) > 0)
		rb(stack_b, 0);
	pb(stack_a, stack_b, 0);
}

void	a_rrarrb(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	while((*stack_a)->nb != a && find_index(*stack_b, b) > 0)
		rrr(stack_a, stack_b, 0);
	while ((*stack_a)->nb != a)
		rra(stack_a, 0);
	while (find_index(*stack_b, b) > 0)
		rrb(stack_b, 0);
	pb(stack_a, stack_b, 0);
}

void	a_rarrb(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	while ((*stack_a)->nb != a && find_index(*stack_b, b) > 0)
	{
		ra(stack_a, 0);
		rrb(stack_b, 0);
	}
	while ((*stack_a)->nb != a)
		ra(stack_a, 0);
	while (find_index(*stack_b, b) > 0)
		rrb(stack_b, 0);
	pb(stack_a, stack_b, 0);
}

void	a_rrarb(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	while ((*stack_a)->nb != a && find_index(*stack_b, b) > 0)
	{
		rra(stack_a, 0);
		rb(stack_b, 0);
	}
	while ((*stack_a)->nb != a)
		rra(stack_a, 0);
	while (find_index(*stack_b, b) > 0)
		rb(stack_b, 0);
	pb(stack_a, stack_b, 0);
}

void	do_steps_ab(t_stack **stack_a, t_stack **stack_b)
{
	int		best;
	int		size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		set_index(stack_a, size);
		set_index(stack_b, stack_size(*stack_b));
		get_steps_ab(stack_a, stack_b);
		best = perfect_match(*stack_a);
		if (best == (*stack_a)->steps && (*stack_a)->upper == true
			&& (find_index(*stack_b, (*stack_a)->match_a) < get_mid(*stack_b)))
			a_rarb(stack_a, stack_b, (*stack_a)->nb, (*stack_a)->match_a);
		else if (best == (*stack_a)->steps && (*stack_a)->upper == false
			&& (find_index(*stack_b, (*stack_a)->match_a) > get_mid(*stack_b)))
			a_rrarrb(stack_a, stack_b, (*stack_a)->nb, (*stack_a)->match_a);
		else if (best == (*stack_a)->steps && (*stack_a)->upper == true
			&& (find_index(*stack_b, (*stack_a)->match_a) > get_mid(*stack_b)))
			a_rarrb(stack_a, stack_b, (*stack_a)->nb, (*stack_a)->match_a);
		else if (best == (*stack_a)->steps && (*stack_a)->upper == false
			&& (find_index(*stack_b, (*stack_a)->match_a) < get_mid(*stack_b)))
			a_rrarb(stack_a, stack_b, (*stack_a)->nb, (*stack_a)->match_a);
		size--;
	}
}

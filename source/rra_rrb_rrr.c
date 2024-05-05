/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:44:29 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/05 18:19:28 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack_a, int print)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*top;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a);
	last = find_last(*stack_a);
	top = (*stack_a)->next;
	tmp->next = NULL;
	(*stack_a) = top;
	if (print == 0)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b, int print)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*top;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b);
	last = find_last(*stack_b);
	top = (*stack_b)->next;
	tmp->next = NULL;
	(*stack_b) = top;
	if (print == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (print == 0)
		ft_putstr_fd("rrr\n", 1);
}

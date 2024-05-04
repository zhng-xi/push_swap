/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:01:36 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 13:38:29 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack_a, int print)
{
	t_stack	*last;
	t_stack	*head;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = find_last(*stack_a);
	head = (*stack_a)->next;
	last->next = (*stack_a);
	last = last->next;
	last->next = NULL;
	*stack_a = head;
	if (print == 0)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b, int print)
{
	t_stack	*last;
	t_stack	*head;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = find_last(*stack_b);
	head = (*stack_b)->next;
	last->next = (*stack_b);
	last = last->next;
	last->next = NULL;
	*stack_b = head;
	if (print == 0)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	ra(a, 1);
	rb(b, 1);
	if (print == 0)
		ft_putstr_fd("rr\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:58:09 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 13:38:01 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
	*stack = NULL;
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

bool	check_double(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*check;

	check = *stack;
	while (check)
	{
		tmp = check->next;
		while (tmp)
		{
			if (check->nb == tmp->nb)
				return (true);
			tmp = tmp->next;
		}
		check = check->next;
	}
	return (false);
}

bool	check_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

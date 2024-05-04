/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:49:41 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 21:20:00 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_order(t_stack **stack)
{
	int		i;
	int		cur_min;
	int		size;
	t_stack	*tmp;
	t_stack	*tmp2;

	i = 1;
	tmp = (*stack);
	tmp2 = tmp;
	cur_min = get_min(tmp);
	size = stack_size(tmp);
	while (i <= size)
	{
		while (tmp2)
		{
			if (tmp2->nb == cur_min)
			{
				tmp2->io = i;
				i++;
			}
			if (!tmp2->next)
				break ;
			tmp2 = tmp2->next;
		}
		tmp2 = (*stack);
		tmp = tmp2;
		cur_min++;
	}
}

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
	if (find_index(*stack_b, (*stack_b)->nb) <= len)
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
	int		i;
	int		size;
	t_stack	*tmp;
	t_stack	*tmp2;

	i = 0;
	tmp = (*stack_b);
	tmp2 = tmp;
	size = stack_size(*stack_b);
	while (i++ < size)
	{
		while (tmp2)
		{
			if (i == tmp2->io)
			{
				if (tmp2->io > (*stack_a)->nb)
					(*stack_a)->match = tmp2->nb;
			}
			tmp2 = tmp2->next;
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return ((*stack_a)->match);
}

int	find_match_ba(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		size;
	t_stack	*tmp;
	t_stack	*tmp2;

	i = 0;
	tmp = (*stack_a);
	tmp2 = tmp;
	size = stack_size(*stack_a);
	while (i++ < size)
	{
		while (tmp2)
		{
			if (i == tmp2->io)
			{
				if (tmp2->io < (*stack_b)->io)
					(*stack_b)->match = tmp2->nb;
			}
			tmp2 = tmp2->next;
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return ((*stack_b)->match);
}

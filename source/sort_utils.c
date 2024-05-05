/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:49:41 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/05 09:02:02 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_order(t_stack **stack)
{
	int		i;
	int		cur_min;
	int		size;
	t_stack	*tmp;

	i = 1;
	tmp = (*stack);
	cur_min = get_min(tmp);
	size = stack_size(tmp);
	while (i <= size)
	{
		while (tmp)
		{
			if (tmp->nb == cur_min)
			{
				tmp->io = i;
				i++;
			}
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp = (*stack);
		cur_min++;
	}
}

void	calc_a(t_stack **stack_a, int size)
{
	int	len;

	len = size / 2;
	if ((*stack_a)->i <= len)
	{
		(*stack_a)->cost = (*stack_a)->i - 1;
		(*stack_a)->upper = true;
	}
	else
	{
		(*stack_a)->cost = size - (*stack_a)->i + 1;
		(*stack_a)->upper = false;
	}
}

void	calc_b(t_stack **stack_b, int size)
{
	int	len;

	len = size / 2;
	if ((*stack_b)->i <= len)
	{
		(*stack_b)->cost = (*stack_b)->i - 1;
		(*stack_b)->upper = true;
	}
	else
	{
		(*stack_b)->cost = size - (*stack_b)->i + 1;
		(*stack_b)->upper = false;
	}
}

void	find_match_a(t_stack **stack_a, t_stack **store, int size)
{
	int		i;
	int		min;
	int		max;
	t_stack	*tmp;

	i = (*stack_a)->io + 1;
	min = get_min(*store);
	max = get_max(*store);
	tmp = (*store);
	while(size > 0)
	{
		tmp = (*store);
		while (tmp)
		{
			if (size == tmp->io)
			{
				if (tmp->nb == max)
					(*stack_a)->match_a = min;
				if (tmp->io == i)
					(*stack_a)->match_a = tmp->nb;
			}
			tmp = tmp->next;
		}
		size--;
	}
}

void	find_match_b(t_stack **stack_b, t_stack **store, int size)
{
	int		i;
	int		min;
	int		max;
	t_stack	*tmp;

	i = 0;
	min = get_min(*store);
	max = get_max(*store);
	tmp = (*store);
	while(i++ < size)
	{
		while (tmp)
		{
			if (i == tmp->io)
			{
				if (tmp->nb == min)
					(*stack_b)->match_b = max;
				if (tmp->io < (*stack_b)->io)
					(*stack_b)->match_b = tmp->nb;
			}
			tmp = tmp->next;
		}
		tmp = (*store);
	}
}

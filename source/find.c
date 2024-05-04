/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:41:01 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 21:10:55 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	min = stack->nb;
	tmp = stack;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = stack->nb;
	tmp = stack;
	while (tmp)
	{
		if (max < tmp->nb)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*find_last(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	find_index(t_stack *stack, int nb)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (i);
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

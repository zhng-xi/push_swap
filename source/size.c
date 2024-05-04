/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 22:09:18 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 13:38:40 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	stack_size(t_stack *stack)
{
	long	i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	get_mid(t_stack *stack)
{
	int	size;
	int	half;

	size = stack_size(stack);
	if (size % 2 == 0)
		half = size / 2;
	else
	{
		size -= 1;
		half = size / 2;
	}
	return (half);
}

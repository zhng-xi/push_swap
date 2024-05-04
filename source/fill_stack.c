/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:48:50 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 13:38:14 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_stack(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_stack **stack, t_stack *addon)
{
	t_stack	*last;

	last = find_last(*stack);
	if (!last)
		*stack = addon;
	else
		last->next = addon;
	addon->next = NULL;
}

t_stack	*split_input(char *av)
{
	t_stack	*stack_a;
	t_stack	*new;
	char	**tmp;
	int		i;
	int		j;
	 

	stack_a = NULL;
	i = 0;
	tmp = ft_split(av, ' ');

	if (tmp == NULL || tmp[0] == NULL)
		error();
	while (tmp[i])
	{
		j = ft_atol(tmp[i]);
		free(tmp[i]);
		new = new_stack(j);
		if (!new)
			return (free(tmp), free_stack(&stack_a), error(), NULL);
		add_to_stack(&stack_a, new);
		i++;
	}
	free(tmp);
	return (stack_a);
}

t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*new;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;
	if (ac == 2)
	{
		if (ft_strchr(av[1], ' ') != 0)
			return (stack_a = split_input(av[1]));
		else
			exit(0);
	}
	while (i < ac)
	{
		j = ft_atol(av[i]);
		new = new_stack(j);
		if (!new)
			return (free_stack(&stack_a), error(), NULL);
		add_to_stack(&stack_a, new);
		i++;
	}
	return (stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:49:16 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 13:38:22 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	prenum(const char *nptr)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while ((nptr[j] >= '\t' && nptr[j] <= '\r') || nptr[j] == ' '
		|| (nptr[j] == '+' || nptr[j] == '-'))
	{
		if (nptr[j] == '+' || nptr[j] == '-')
		{
			count++;
			if (count <= 1)
			{
				if ((nptr[j + 1] >= '\t' && nptr[j + 1] <= '\r')
					|| nptr[j + 1] == ' ')
					return (0);
			}
			else if (count > 1)
				return (0);
		}
		j++;
	}
	return (j);
}

static int	op(int j, const char *nptr)
{
	int	o;

	o = 1;
	if ((nptr[j - 1] == '-' && (j - 1) >= 0)
		&& (nptr[j] >= '0' && nptr[j] <= '9'))
		o = -1;
	else if ((nptr[j - 1] == '+' && (j - 1) >= 0)
		&& (nptr[j] >= '0' && nptr[j] <= '9'))
		o = 1;
	return (o);
}

void	is_error(char *nptr)
{
	if (!nptr)
		error();
}

long	ft_atol(char *nptr)
{
	int		i;
	int		over;
	long	nb;
	int		o;

	is_error(nptr);
	i = prenum(nptr);
	nb = 0;
	over = 0;
	o = op(i, nptr);
	while (nptr[i])
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9') || over > 11)
			error();
		else
		{
			nb *= 10;
			nb += nptr[i] - '0';
			over++;
		}
		i++;
	}
	if ((nb * o) > INT_MAX || (nb * o) < INT_MIN)
		error();
	return (nb * o);
}

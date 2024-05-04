/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:00:50 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/24 16:59:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n-- > 0)
	{
		if (*p == (unsigned char)c)
		{
			return ((void *)p);
		}
		p++;
	}
	return (0);
}

/*#include <stdio.h>

int	main()
{
	char	str[] = "Does my code work";
	char	*test;
	//char	*test2;
	int	p = '\0';
	int	q = 20;

	test = memchr(str, p, q);
	printf("The first occurance of '%c' in '%s' is '%s'\n", p, str, test);
	//test2 = ft_memchr(str, p, q);
	//printf("The first occurance of '%c' in '%s' is '%s'\n", p, str, test2);
	return (0);
}
A void pointer in C is a pointer that can point to any type of data.
It is declared using the void * syntax.
Void pointers are useful for writing generic functions
and for working with memory allocation.*/
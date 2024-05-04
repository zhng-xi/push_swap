/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:01:41 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/03 20:31:02 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		*p = (char)c;
		p++;
		i++;
	}
	return (p - n);
}

/*#include <stdio.h>

int	main()
{
	char	s[40] = "Programmieren ist einfach, they said";
	size_t	n = 6;
	printf("%s\n", (unsigned char *)ft_memset(s, 'x', n*sizeof(char)));
	//memset(s, 'x', n*sizeof(char));
	//printf("%s\n", s);
	return (0);
}
memset replaces chars with chars*/

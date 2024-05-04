/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:30:47 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/24 15:22:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*to;
	const unsigned char	*from;

	to = (unsigned char *)dest;
	from = (const unsigned char *)src;
	i = 0;
	if (to == from || n == 0)
		return (to);
	if (!to && !from)
		return (NULL);
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (to);
}

/*#include <stdio.h>

int	main()
{
	char	d[70] = "Programmieren ist einfach, they said";
    char	s[] = "Die Funktion hat funktioniert oder vllt auch nicht?";
	size_t	n = 10;
	ft_memcpy(d, s, n*sizeof(char));
	//memcpy(d, s, n*sizeof(char));
	printf("%s\n", d);
	return (0);
}*/
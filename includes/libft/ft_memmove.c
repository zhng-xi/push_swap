/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:06:33 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/24 15:38:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*to;
	unsigned char	*from;

	i = 0;
	to = dest;
	from = (unsigned char *)src;
	if (!to && !from)
		return (0);
	if (to < from)
	{
		while (i++ < n)
			*to++ = *from++;
		return (to - n);
	}
	else
	{
		to += n - 1;
		from += n - 1;
		while (n-- > 0)
			*to-- = *from--;
		return (to + 1);
	}
}

/*#include <stdio.h>

int	main()
{
	char	test1[100] = "waaaaas geht";
	char	test2[5] = "hello";
	//char	test3[8] = "okay";
	size_t	n = 9;
	printf("%s\n", (char *)memmove(test1, test2, n * sizeof(char)));
	//printf("%s\n", (char *)ft_memmove(test1, test2, n * sizeof(char)));
	//ft_memmove(test3, test3, n * sizeof(char));
	//memmove(test3, test3, n * sizeof(char));
	//printf("%s\n", test3);
	return (0);
}*/
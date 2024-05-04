/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:50:24 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/01 21:37:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lil_len;
	size_t	i;
	size_t	j;

	lil_len = ft_strlen(little);
	i = 0;
	j = 1;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			while (j < lil_len && i + j < len && big[i + j] == little[j])
				j++;
			if (j == lil_len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
const char	*largestring = "Foo Bar	 Baz";
	     const char	*smallstring = "Ba";
		 size_t	n = 20;
	     char *ptr;

	     ptr = ft_strnstr(largestring,	smallstring, n);
		 printf("%s\n", ptr);
		 return (0);
}*/
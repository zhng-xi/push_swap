/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:34:02 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/24 17:28:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (!size)
		return (srclen);
	if (size == 0)
		return (0);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (size < srclen)
		dst[size - 1] = '\0';
	else if (size != 0)
		dst[i] = '\0';
	return (srclen);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	char	test[] = "funkts?";
	char	test2[] = "abcdefghijklmno, es tuts oder?";
	size_t	size = 20;

	ft_strlcpy(test, test2, size * sizeof(char));
	//strlcpy(test, test2, size * sizeof(char));
	printf("%s\n", test);
	return (0);
}*/
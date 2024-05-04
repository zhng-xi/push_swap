/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:15:28 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/03 20:34:02 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlength(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	space_left;
	size_t	i;

	dest_len = ft_strlength(dest);
	src_len = ft_strlength(src);
	space_left = size - dest_len - 1;
	i = 0;
	if (size <= dest_len)
		return (size + src_len);
	while (*src && i < space_left)
	{
		dest[dest_len + i] = *src;
		src++;
		i++;
	}
	dest[dest_len + i] = '\0';
	while (*src)
	{
		src++;
		i++;
	}
	return (dest_len + i);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main()
{
	char	test[50] = "funkts?";
	char	test2[] = "abcdefghijklmno, es tuts oder?";
	size_t	size = 4;

	ft_strlcat(test, test2, size * sizeof(char));
	//strlcat(test, test2, size * sizeof(char));
	printf("%s\n", test);
	return (0);
}*/
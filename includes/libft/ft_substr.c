/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:51:57 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/01 20:18:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;
	size_t	srclen;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start >= srclen)
		return (ft_strdup(""));
	if (len > srclen - start)
		len = srclen - start;
	substr = (char *)malloc (sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (s[i] && i < start)
		i++;
	while (j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}

/*#include <stdio.h>

int	main()
{
	char const str[] = "Teste diesen string";
	unsigned int init = 5;
	int	length = 5;
	char	*sub;

	sub = ft_substr(str, init, length);
	printf("%s\n", sub);
	return (0);
}*/
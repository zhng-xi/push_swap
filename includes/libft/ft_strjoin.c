/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:28:00 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/19 19:07:55 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (i < size)
	{
		while (*s1 != '\0')
			new[i++] = *s1++;
		while (*s2 != '\0' && *s1 == 0)
			new[i++] = *s2++;
	}
	new[i] = '\0';
	return (new);
}

/*#include <stdio.h>

int	main()
{
	char const	str1[] = "erster string braucht einen ";
	char const	str2[] = "zweiten string";
	char	*joined;

	joined = ft_strjoin(str1, str2);
	printf("%s\n", joined);
	return (0);
}*/
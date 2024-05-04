/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:24:07 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/24 21:16:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;

	start = 0;
	end = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	while (check_char(s1[start], set) == 1)
		start++;
	if (start == ft_strlen(s1))
	{
		trim = ft_strdup("");
		if (!trim)
			return (NULL);
		else
			return (trim);
	}
	while (check_char(s1[end - 1], set) == 1)
		end--;
	trim = ft_substr(s1, start, end - start);
	return (trim);
}

/*#include <stdio.h>

int	main()
{
	char	str[] = "trim this";
	char	rem[] = "th";
	char	*trimmed;

	trimmed = ft_strtrim(str, rem);
	printf("%s\n", trimmed);
	return (0);
}*/
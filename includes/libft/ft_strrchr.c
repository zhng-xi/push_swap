/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:37:05 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/03 20:35:44 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	const char	*last_occurrence;

	i = 0;
	last_occurrence = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last_occurrence = s + i;
		i++;
	}
	if (s[i] == (char)c)
		last_occurrence = (char *)(s + i);
	return ((char *)last_occurrence);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	char	str[] = "Does my code work";
	//char	*test;
	char	*test2;
	int	p = 'o';

	//test = strchr(str, p);
	test2 = ft_strrchr(str, p);
	printf("The last occurance of of '%c' in '%s' is '%s'\n", p, str, test2);
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:22:00 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/01 20:08:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char *)s;
	while ((a[i] != (char)c) && (a[i] != '\0'))
		i++;
	if (a[i] == (char)c)
		return (&a[i]);
	return (0);
}

/*#include <string.h>
#include <stdio.h>

int	main()
{
	char	str[] = "Does my code work";
	//char	*test;
	char	*test2;
	int	p = 'm';

	//test = strchr(str, p);
	//printf("The first occurance of '%c' in '%s' is '%s'\n", p, str, test);
	test2 = ft_strchr(str, p);
	printf("The first occurance of '%c' in '%s' is '%s'\n", p, str, test2);
	return (0);
}
i could have also leave the variable "a" out and just typecast my "s"
to save lines, like the int c */
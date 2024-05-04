/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:06:47 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/18 19:42:11 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	p = (char *)malloc (sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (!p)
		return (NULL);
	while (*s)
		p[i++] = *s++;
	p[i] = '\0';
	return (p);
}

/*#include <stdio.h>


int main()
{
	char    array[] = "test string";
	char    *p;

	p = ft_strdup(array);
	printf("%s\n", p);
	return (0);
}*/

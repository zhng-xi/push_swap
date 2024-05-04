/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:04:54 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/03 20:34:22 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	const char	str[] = "dsf";
	printf("%d\n", ft_strlen(str));
	printf("%lu\n", strlen(str));
	return (0);
}*/
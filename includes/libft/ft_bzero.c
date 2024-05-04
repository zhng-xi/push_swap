/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:45:39 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/16 12:38:40 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n * sizeof(char));
}

/*#include <stdio.h>

int	main()
{
	char	s[40] = "Programmieren ist einfach, they said";
	//char	c[40] = "Programmieren ist einfach, they said";
	size_t	n = 40;
    ft_bzero(s+4, n*sizeof(char));
	printf("%s\n", s);
	//bzero(c+4, n*sizeof(char));
	//printf("%s\n", c);
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:12:59 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/16 12:21:07 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (8);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int	main()
{
	int c = 'b';
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", isalnum(c));
}*/
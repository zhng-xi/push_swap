/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:16:11 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/01 12:39:14 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int main()
{
	int	str = 'R';
	printf("%d\n", ft_toupper(str));
	printf("%d\n", toupper(str));
	return (0);
}*/
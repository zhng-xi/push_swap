/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:14:39 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/16 12:21:08 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int main()
{
	int	str = 'r';
	printf("%d\n", ft_isalpha(str));
	printf("%d\n", isalpha(str));
	return (0);
}*/

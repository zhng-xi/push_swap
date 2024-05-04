/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:52:24 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/16 12:21:10 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (2048);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int	main()
{
	int	digit = '7';
	printf("%d\n", ft_isdigit(digit));
	printf("%d\n", isdigit(digit));
	return (0);
}*/

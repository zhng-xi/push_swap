/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:43:01 by xzheng            #+#    #+#             */
/*   Updated: 2023/09/21 12:43:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c >= 32 && c < 127))
		return (16384);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int	main()
{
	int str = '3';
    printf("%d\n", isprint(str));
    printf("%d\n", ft_isprint(str));
    return (0);
}*/
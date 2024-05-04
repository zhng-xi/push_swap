/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:26:16 by xzheng            #+#    #+#             */
/*   Updated: 2023/10/01 21:42:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*intmin(int n)
{
	char	*str;

	str = NULL;
	if (n == -2147483648)
	{
		str = (char *)malloc(sizeof(char) * 12);
		if (!str)
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = intlen(n);
	if (n == -2147483648)
		return (intmin(n));
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	if (n < 0)
		n *= (-1);
	while (n)
	{
		str[len -1] = n % 10 + 48;
		len--;
		n /= 10;
	}
	return (str);
}

/*#include <stdio.h>

int	main()
{
	int	z;
	z = -2147483648;

	printf("%s\n", ft_itoa(z));
	return (0);
}*/
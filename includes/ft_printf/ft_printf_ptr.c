/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:09:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/02 00:43:54 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	ft_printf_hex(long n)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	if (n < 0)
	{
		n = n * -1;
		return (ft_printf_hex(n));
	}
	else if (n < 16)
		return (ft_printf_char(hex[n]));
	else
	{
		i = ft_printf_hex(n / 16);
		return (i + ft_printf_hex(n % 16));
	}
}

int	ft_printf_ptr(void *ptr)
{
	unsigned long	point;

	point = (unsigned long)ptr;
	if (!ptr)
		return (ft_printf_str("(nil)"));
	else
	{
		write (1, "0x", 2);
		return (ft_printf_hex(point) + 2);
	}
	return (0);
}

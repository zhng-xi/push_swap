/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:06:23 by codespace         #+#    #+#             */
/*   Updated: 2023/11/16 21:54:42 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_num(long n, int base, int cap)
{
	int		i;
	char	*hex_low;
	char	*hex_up;

	hex_low = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	if (n < 0)
	{
		if (base != 16)
			write(1, "-", 1);
		if (base != 16)
			return (ft_printf_num(-n, base, cap) + 1);
		else
			return (ft_printf_num(-n, base, cap));
	}
	else if (n < base && cap == 0)
		return (ft_printf_char(hex_low[n]));
	else if (n < base && cap == 1)
		return (ft_printf_char(hex_up[n]));
	else
	{
		i = ft_printf_num(n / base, base, cap);
		return (i + ft_printf_num(n % base, base, cap));
	}
}

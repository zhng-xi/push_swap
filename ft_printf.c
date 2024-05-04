/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:02:09 by codespace         #+#    #+#             */
/*   Updated: 2023/11/16 21:56:05 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	formating(char flags, va_list args)
{
	int	i;

	i = 0;
	if (flags == 'c')
		i += ft_printf_char(va_arg(args, int));
	else if (flags == 's')
		i += ft_printf_str(va_arg(args, char *));
	else if (flags == 'p')
		i += ft_printf_ptr(va_arg(args, void *));
	else if (flags == 'd' || flags == 'i')
		i += ft_printf_num((long)(va_arg(args, int)), 10, 0);
	else if (flags == 'u')
		i += ft_printf_num((long)(va_arg(args, unsigned int)), 10, 0);
	else if (flags == 'x')
		i += ft_printf_num((long)(va_arg(args, unsigned int)), 16, 0);
	else if (flags == 'X')
		i += ft_printf_num((long)(va_arg(args, unsigned int)), 16, 1);
	else
		i += write(1, &flags, 1);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		count;

	va_start(args, input);
	count = 0;
	while (*input != '\0')
	{
		if (*input == '%')
			count += formating(*(++input), args);
		else
			count += write (1, input, 1);
		++input;
	}
	va_end(args);
	return (count);
}

// #include <limits.h>
// #include <stdio.h>

// int main(void)
// {
// 	int i;
// 	i = ft_printf(" %p ", LONG_MIN);
// 	printf("%i\n", i);	

// 	i = printf(" %p ", LONG_MIN);
// 	printf("%i\n", i);	

// 	return(0);
// }

/* variadic functions --> take a variable number of arguments
the var func consists of at least one fixed var
and then an ellipsis "..." as the last parameter
--> int func_name(data_type var_name, ...)
va_list --> declaring pointer --> holds information
va_start(list_name, (pos of arg)) --> enables access to variadic func args
va_arg(list_name, type) --> access next variadic func arg | type expected*/
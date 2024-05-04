/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:15:24 by xzheng            #+#    #+#             */
/*   Updated: 2023/11/16 21:48:28 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf_char(int c);
int	ft_printf_str(char *str);
int	ft_printf_num(long n, int base, int cap);
int	ft_printf_ptr(void *ptr);
int	ft_printf(const char *input, ...);

#endif
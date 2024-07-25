/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:04:41 by sforster          #+#    #+#             */
/*   Updated: 2023/11/27 09:04:41 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_handlevariadics(char print_type, va_list args)
{
	int	i;

	i = 0;
	if (print_type == 'c')
		i += ft_print_c(va_arg(args, int));
	else if (print_type == 's')
		i += ft_print_s(va_arg(args, char *));
	else if (print_type == 'd')
		i += ft_print_d(va_arg(args, int), 10);
	else if (print_type == 'x')
		i += ft_print_x(va_arg(args, unsigned int), 16);
	else if (print_type == 'X')
		i += ft_print_xup(va_arg(args, unsigned int), 16);
	else if (print_type == 'i')
		i += ft_print_i(va_arg(args, int), 10);
	else if (print_type == 'u')
		i += ft_print_u(va_arg(args, unsigned int), 10);
	else if (print_type == '%')
		i += write(1, "%", 1);
	else if (print_type == 'p')
		i += ft_print_p(va_arg(args, void *));
	else
		return (i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		prev_i;
	int		count;
	va_list	args;

	i = 0;
	prev_i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != 0)
	{
		while (format[i] != '%' && format[i] != 0)
			i++;
		write (1, format + prev_i, i - prev_i);
		count += i - prev_i;
		if (format[i] == '%')
		{
			count += ft_handlevariadics(*(format + i + 1), args);
			i += 2;
			prev_i = i;
		}
	}
	va_end(args);
	return (count);
}

/*
int	main(void)
{
	ft_printf("%p\n", "42949672950");
	printf("%p\n", "42949672950");
	return (0);
}
*/
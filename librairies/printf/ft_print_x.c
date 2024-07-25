/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:50:11 by sforster          #+#    #+#             */
/*   Updated: 2023/11/27 09:05:24 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int n, int base)
{
	int		count;
	char	*basesymbols;

	count = 0;
	basesymbols = "0123456789abcdef";
	if (n == 0)
		return (count = write(1, "0", 1));
	while (n >= (unsigned int)base)
	{
		count += ft_print_x(n / (unsigned int)base, base);
		n = n % base;
	}
	if (n < (unsigned int)base)
	{
		write(1, &basesymbols[n], 1);
		count++;
	}
	return (count);
}

/*
int main(void)
{
	ft_print_x(-20, 16);
}


int	ft_print_x(long n, int base)
{
	int		count;
	char	*basesymbols;

	count = 0;
	basesymbols = "0123456789abcdef";
	if (n == 0)
		return(count = write(1, "0", 1));
	if (n < 0)
	{
		count = write (1, "-", 1);
		n = -n;
		basesymbols = "fedcba9876543210";
	}
	while (n >= base)
	{
		count += ft_print_x(n / base, base);
		n = n % base;
	}
	if (n < base)
	{
		write(1, &basesymbols[n], 1);
		count++;
	}
	return (count);
}


fedcba9876543210




int ft_print_xneg(long n, int base)
{
	int i;
	char	*basesymbneg;

	i = 0;
	basesymbneg = "fedcba9876543210";
	while (n >= base)
	{
		ft_print_xneg(n / base, base);
		n = n % base;
	}
		if (n < base)
			write(1, &basesymbneg[n], 1);
	return (8);
}

int	ft_print_x(long n, int base)
{
	int		count;
	char	*basesymbols;

	count = 0;
	basesymbols = "0123456789abcdef";
	if (n == 0)
		return(count = write(1, "0", 1));
	if (n < 0)
	{
		n = -n;
		return (count = ft_print_x(n, 16));
	}
	while (n >= base)
	{
		count += ft_print_x(n / base, base);
		n = n % base;
	}
	if (n < base)
		count += write(1, &basesymbols[n], 1);
	return (count);
}

*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:43:55 by sforster          #+#    #+#             */
/*   Updated: 2023/11/27 09:05:19 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_l(unsigned long long int n, unsigned int base)
{
	int		count;
	char	*basesymbols;

	count = 0;
	basesymbols = "0123456789abcdef";
	if (n == 0)
		return (count = write(1, "0", 1));
	while (n >= (unsigned long long int)base)
	{
		count += ft_print_l(n / (unsigned long long int)base, base);
		n = n % base;
	}
	if (n < (unsigned long long int)base)
	{
		write(1, &basesymbols[n], 1);
		count++;
	}
	return (count);
}

int	ft_print_p(void *n)
{
	int		count;

	count = write(1, "0", 1);
	count += write(1, "x", 1);
	if (n == NULL)
		return (count += write(1, "0", 1));
	count += ft_print_l((unsigned long long int)n, 16);
	return (count);
}

/*

int	ft_print_p(void *n, int base)
{
	int		count;
	char	*basesymb;

	basesymb = "0123456789abcdef";
	count = write(1, "0", 1);
	count += write(1, "x", 1);
	while (n >= base)
	{
		count += ft_print_p(n / base, base);
		n = n % base;
	}
	if (n < base)
	{
		write(1, &basesymb[n], 1);
		count++;
	}
	return (count);
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:03:37 by sforster          #+#    #+#             */
/*   Updated: 2023/11/27 09:03:37 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(long n, int base)
{
	int		count;
	char	*basesymb;

	count = 0;
	basesymb = "0123456789";
	if (n == 0)
		return (count = write (1, "0", 1));
	if (n < 0)
	{
		count = write (1, "-", 1);
		n = -n;
	}
	while (n >= base)
	{
		count += ft_print_d(n / base, base);
		n = n % base;
	}
	if (n < base)
	{
		write (1, &basesymb[n], 1);
		count++;
	}
	return (count);
}

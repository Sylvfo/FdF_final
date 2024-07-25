/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:04:29 by sforster          #+#    #+#             */
/*   Updated: 2023/11/27 09:04:29 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xup(unsigned int n, int base)
{
	int		count;
	char	*symbbase;

	count = 0;
	symbbase = "0123456789ABCDEF";
	if (n == 0)
		return (count = write(1, "0", 1));
	while (n >= (unsigned int)base)
	{
		count += ft_print_xup(n / (unsigned int)base, base);
		n = n % base;
	}
	if (n < (unsigned int) base)
	{
		write (1, &symbbase[n], 1);
		count++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:40:07 by sforster          #+#    #+#             */
/*   Updated: 2023/11/27 09:05:17 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_i(long i, int base)
{
	int		count;
	char	*basesymb;

	basesymb = "0123456789";
	count = 0;
	if (i == 0)
		return (count = write (1, "0", 1));
	if (i < 0)
	{
		count = write(1, "-", 1);
		i = -i;
	}
	while (i >= base)
	{
		count += ft_print_i(i / base, base);
		i = i % base;
	}
	if (i < base)
	{
		write(1, &basesymb[i], 1);
		count++;
	}
	return (count);
}
/*int main(void)
{
	ft_print_i(56, 10);
}*/
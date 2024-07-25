/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:07:13 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:48:41 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate number
// integer to ascii. Converti un chiffre int (nb) en string de char.

#include "libft.h"

int	ft_nbrlen(int nb)
{
	int	co;

	co = 0;
	if (nb < 0)
	{
		co++;
		nb = nb * -1;
	}
	if (nb == 0)
		co++;
	while (nb != 0)
	{
		nb /= 10;
		co++;
	}
	return (co);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	unsigned int	len;
	char			*result;

	len = ft_nbrlen(n);
	result = malloc(len + 1 * sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	if (nb == 0)
		result[0] = '0';
	result[len] = '\0';
	while (nb != 0)
	{
		result[len -1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (result);
}

/*
int	main(void)
{
	printf("%s\n", ft_itoa(0));
	return (0);
}*/

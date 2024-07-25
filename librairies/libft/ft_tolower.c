/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:29:36 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:50:37 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check and manipulate characteres
// met une majuscule en minuscule

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/*int	main(void)
{
	int	a = '2';
	int b = 'a';
	int c = 'T';
	int d = ')';

	printf("%c\n", ft_tolower(a));
	printf("%c\n", ft_tolower(b));
	printf("%c\n", ft_tolower(c));
	printf("%c\n", ft_tolower(d));
	return (0);
}*/
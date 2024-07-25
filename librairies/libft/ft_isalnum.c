/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:41:41 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:48:32 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check and manipulate character
// verifie si (c) est un chiffre ou une lettre dans ascii

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

/*int main(void)
{
	int    d;
	d = 'K';
	int    e;
	e = '/';
	int    f;
	f = '0';
	int    g;
	g = 'T';
	int    h;
	h = 'z';

	printf("%i\n", ft_isalnum(d));
	printf("%i\n", ft_isalnum(e));
	printf("%i\n", ft_isalnum(f));
	printf("%i\n", ft_isalnum(g));
	printf("%i\n", ft_isalnum(h));
}*/
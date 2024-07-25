/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:44:17 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:48:36 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check and manipulate character
// verifie si (c) est dans ascii

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int main(void)
{
    int a;
    a = '1';

    printf("%i\n", ft_isascii(a));
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:38:12 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:48 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate string
// applique une fonction (f) a tous les char d'une string(s)
// la taille de la string ne change pas
// renvoie rien contrairement a mapi qui retourne la string

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:49:25 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:25 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate string
// recherche 1ere occurence du charactere (c) dans une string (s)
// comme memchr (dans un bloque de memoire) et strrchr (derniere occurence)

#include "libft.h"
/*#include <stdio.h>*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == (unsigned char) c)
		return ((char *) s + i);
	return (NULL);
}

/*int main(void)
{
    const char *str = "Salut toi!";

    printf("%s", ft_strchr(str, 'z'));
    return (0);
}*/
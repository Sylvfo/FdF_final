/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:08:21 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:55 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate string
// copie source dans la destination et retourne taille source
// la source remplace la destination
// l ca veut dire un zero a la fin

#include "libft.h"
#include <stdio.h>

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	sizesrc;

	sizesrc = ft_strlen(src);
	if (sizesrc + 1 < dstsize)
	{
		ft_memmove(dst, src, sizesrc + 1);
	}
	else if (dstsize != 0)
	{
		ft_memmove(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (sizesrc);
}
/*
int	main(void)
{
	char	dest[] = "Arbre ";
	char	src[] = "Serpent a sonette";
	printf("premiere %u %s\n", ft_strlcpy(dest, src, 78), dest);
	
	char	dd[] = "Hello bonjour";
	char	hu[] = "Tu e";
	printf("deuxieme %u %s\n", ft_strlcpy(dd, hu, 12), dd);
	return (0);	
}


int	ft_strlen(int *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

}*/
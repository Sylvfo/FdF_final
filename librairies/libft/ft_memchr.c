/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:24:05 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:48:43 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate memory
// cherche 1er (c) dans la taille (n) d un bloque de memoire (s)
// difference avec strchr c est que ca s arrete pas a '\0'
// unsigned char pour eviter des erreurs si char speciaux ascii-etendu

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "wourgwealila";

	printf("%s\n", ft_memchr(str, 'q', 15));
	return (0);
}
*/
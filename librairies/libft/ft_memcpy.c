/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:43:00 by marvin            #+#    #+#             */
/*   Updated: 2023/10/25 17:43:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate memory
// Copie (src) dans (dest) jusqu a (n)
// pareil que strlcpy sauf ne prend pas '\0' en compte.  

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if ((!dst) && (!src))
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}

/*
int	main(void)
{
	char	dest[25] = "Bonjour";
	char	sour[] = "sole";

	printf("%s\n%s\n", ft_memcpy(dest, sour, 4), dest);
	return (0);
}*/
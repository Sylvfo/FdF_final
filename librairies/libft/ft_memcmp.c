/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:30:02 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:48:45 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate mem
// compare 2 blocs de memoire jusqu a la taille n. ret 0, neg ou pos
// retour 0 si idem, retour pos si valeur ascii s1[i] > s2[i]
// et et neg si s1[i] < s2[i]
// similaire a str(l)cmp, sauf que s arrete pas a '\0'

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}

/*
int main(void)
{
	char	a1[] = "Blab";
	char	a2[] = "Blat";

	printf("%d\n", ft_memcmp(a1, a2, 5));
	return (0);
}*/
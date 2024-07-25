/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:25:49 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:53 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate string
// concatene deux string max dstsize. retourne taille operation
// retourne la taille de cette operation et non pas la string dest. 
// l pour toujours NUL terminating. 

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sd;
	size_t	ss;

	sd = ft_strlen(dst);
	ss = ft_strlen(src);
	if (sd > dstsize)
	{
		sd = dstsize;
		return (sd + ss);
	}
	if (sd == dstsize)
		return (sd + ss);
	if (sd + ss < dstsize)
		ft_memcpy(dst + sd, src, ss + 1);
	else
	{
		ft_memcpy(dst + sd, src, dstsize - sd - 1);
		dst[dstsize - 1] = '\0';
	}
	return (sd + ss);
}

/*

	if (sd == dstsize)
		return (sd + ss);

int	main(void)

	char	dest[] = "Salut ";
	char	src[] = "Je crois que je suis parti la bas";
	printf("premiere %u %s\n", ft_strlcat(dest, src, 100), dest);
	
	char	dd[] = "Hello ";
	char	hu[] = "Tu es parti en amerique";
	printf("deuxieme %u %s\n", ft_strlcat(dd, hu, 50), dd);
	return (0);
}*/
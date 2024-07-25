/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:26:25 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:08 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate memory
// rempli la memoire de (s) avec char choisi (c) jusqu'a (len)  
// idem que bzero mais on peut choisir caractere. 

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (b);
}

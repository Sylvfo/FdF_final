/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:48:05 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:48:05 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate memory
// rempli la memoire de (s) avec 0 jusqu'a n 
//fonction liees: memset

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

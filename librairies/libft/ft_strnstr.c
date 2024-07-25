/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:32:00 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:50:16 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate string
// cherche une aiguille string dans max l de botte de foin 
// strchr idem mais il recherche seulement un char. 

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *needle, size_t l)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)hays);
	while (hays[i] && i < l)
	{
		while (hays[i + j] == needle[j] && hays[i + j] && i + j < l)
		{
			j++;
			if (needle[j] == 0)
				return ((char *)hays + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

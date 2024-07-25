/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:50:22 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:50:22 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate string
// recherche la derniere occurence d une char dans une string. 

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;
	char	cc;

	cc = (char)c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			res = ((char *)s + i);
		i++;
	}
	if (s[i] == cc)
		res = ((char *)s + i);
	return (res);
}

/*
int main(void)
{
    const char *str = "Chaussette";

    printf("%s\n", ft_strrchr(str, '\0'));
    return (0);
}


char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	*res;
	char	cc;

	a = ft_strlen(s) + 1;
	if (c == '\0')
		return ((char *)s + a);
	while (a >= 0)
	{
		if (s[a] == c)
			return ((char *)s + a);
		a--;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = ft_strlen(s);
	while (a >= 0)
	{
		if (s[a] == c)
			return ((char *) s + a);
		a--;
	}
	return (NULL);
}

*/
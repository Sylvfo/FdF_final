/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:04:32 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:50:33 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//manipulate string
// trim = tailler
// enleve tous  les characteres du set au debut et a la fin de string s1

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

/*
int	main(void)
{
	printf("%s\n", ft_strtrim("", ""));
}


int	main(void)
{
	char const	sl[] = "";
	char const	st[] = "";

	printf("%s\n", ft_strtrim(sl, st));
	return (0);
}


char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;

	res = 0;
	if (!s1)
		res = ft_strdup(0);
	if (!set)
		res = (ft_strdup(s1));
	if ((s1 != 0) && (set != 0))
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		res = (char *)malloc((j - i + 1) * sizeof(char));
		if (res)
			ft_strlcpy(res, &s1[i], (j - i + 1));
	}
	return (res);
}
*/
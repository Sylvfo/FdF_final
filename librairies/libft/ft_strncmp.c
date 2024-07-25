/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:50:08 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:50:08 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// manipulate string
// compare 2 string jusqu a la taille n. ret 0, neg ou pos
// retourne diff entre les premieres lettres qui sont differentes
// n pour taille maximale. idem que memcmp mais string et prend '\0' en compte

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
int main(void)
{
    const char *str1 = "\200";
    const char *str2 = "\0";

    printf("%d", ft_strncmp(str1, str2, 4));
    return (0);
}*/
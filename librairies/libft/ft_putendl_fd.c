/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:12:28 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:11 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// write to a file descriptor
// comme putstr_fd, mais avec un aller a la ligne

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
	write (fd, "\n", 1);
}

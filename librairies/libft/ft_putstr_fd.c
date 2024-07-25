/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:04:44 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:15 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// write to a file descriptor
// ecrit une string (s) dans le (fd) file descriptor

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

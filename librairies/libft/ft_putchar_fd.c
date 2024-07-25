/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:53:23 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:10 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// write to a file descriptor
// ecrit un caractere dans le (fd) file descriptor

#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

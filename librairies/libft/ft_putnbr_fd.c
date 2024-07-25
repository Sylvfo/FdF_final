/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:19:47 by sforster          #+#    #+#             */
/*   Updated: 2023/11/07 14:49:13 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// write to a file descriptor
// ecrit un nombre int dans le (fd) file descriptor

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			num[12];
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		write (fd, "-", 1);
		un = -n;
	}
	else
		un = n;
	if (un == 0)
		write (fd, "0", 1);
	while (un != 0)
	{
		num[i] = (un % 10) + '0';
		un = un / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write (fd, &num[i], 1);
	}
}

/*
int main(void)
{
	int	num1 = 57;
	int	ff = 1;

	ft_putnbr_fd(num1, ff);
	int	num2 = 0;
	int	ff2 = 1;

	ft_putnbr_fd(num2, ff2);
	return (0);
}
*/
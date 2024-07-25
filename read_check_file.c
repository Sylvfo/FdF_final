/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:07:58 by sforster          #+#    #+#             */
/*   Updated: 2024/06/12 14:57:11 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	check_arg(int argc)
{
	if (argc != 2)
	{
		ft_printf("usage: ./fdf filename.fdf\n");
		return (false);
	}
	return (true);
}

bool	check_extention(char *str)
{
	int	i;

	i = (ft_strlen(str) - 4);
	if (str[i] != '.')
	{
		ft_printf("please enter namefile.fdf\n");
		return (false);
	}
	else if (str[i + 1] != 'f')
	{
		ft_printf("please enter namefile.fdf\n");
		return (false);
	}
	else if (str[i + 2] != 'd')
	{
		ft_printf("please enter namefile.fdf\n");
		return (false);
	}
	else if (str[i + 3] != 'f')
	{
		ft_printf("please enter namefile.fdf\n");
		return (false);
	}
	return (true);
}

bool	check_fd(int fd, char *tomap)
{
	if (fd <= 0)
	{
		ft_printf("issue with the file\n");
		free (tomap);
		return (false);
	}
	return (true);
}

bool	check_map(t_map *map)
{
	if (!map)
	{
		ft_printf("no map\n");
		return (false);
	}
	return (true);
}

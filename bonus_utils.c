/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:36:32 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 13:56:43 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_y_count(t_map *map)
{
	int	i;

	i = 0;
	while (map->nextx != NULL && map->ybase == map->nextx->ybase)
	{
		i++;
		map = map->nextx;
	}
	return (i);
}

int	ft_x_count(t_map *map)
{
	int	i;

	i = 0;
	while (map->nextx != NULL && map->xbase == map->nexty->xbase)
	{
		i++;
		map = map->nexty;
	}
	return (i + 1);
}

int	ft_max_z(t_map *map)
{
	int	i;

	i = 0;
	while (map)
	{
		if (map->z > i)
			i = map->z;
		map = map->nexty;
	}
	return (i);
}

int	ft_min_z(t_map *map)
{
	int	i;

	i = 3000;
	while (map)
	{
		if (map->z < i)
			i = map->z;
		map = map->nexty;
	}
	return (i);
}

int	ft_z_count(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map)
	{
		if (map->z > i)
		{
			i = map->z;
			j++;
		}
		map = map->nexty;
	}
	return (j);
}

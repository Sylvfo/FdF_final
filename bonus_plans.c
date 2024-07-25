/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_plans.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:41 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 14:37:34 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	front(t_map *map)
{
	while (map != NULL)
	{
		map->xiso = map->x * 10;
		map->yiso = map->z * -10;
		map = map->nextx;
	}
	ft_printf("front\n");
	return ;
}

void	plan(t_map *map)
{
	while (map != NULL)
	{
		map->xiso = map->x * 10;
		map->yiso = map->y * 10;
		map = map->nextx;
	}
	ft_printf("plan\n");
	return ;
}

void	side(t_map *map)
{
	while (map)
	{
		map->xiso = map->y * -10;
		map->yiso = map->z * -10;
		map = map->nextx;
	}
	ft_printf("side\n");
	return ;
}

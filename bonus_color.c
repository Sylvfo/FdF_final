/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:42:51 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 14:34:38 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_colors_find(t_data *ima)
{
	if (ima->color == 19)
		ft_white(ima->map);
	else if (ima->color == 18)
		ft_col_base(ima->map);
	else if (ima->color == 20)
		ft_blue(ima->map);
	else if (ima->color == 21)
		ft_light_on_ice(ima);
	else if (ima->color == 23)
		ft_blue_green(ima);
	return ;
}

void	ft_white(t_map *map)
{
	while (map)
	{
		map->color = 0xFFFFFF;
		map = map->nextx;
	}
	return ;
}

void	ft_col_base(t_map *map)
{
	while (map)
	{
		map->color = map->colorbase;
		map = map->nextx;
	}
	return ;
}

void	ft_blue(t_map *map)
{
	while (map)
	{
		map->color = 0x4C86B3;
		map = map->nextx;
	}
	return ;
}

void	ft_light_on_ice(t_data *ima)
{
	float	diff;
	int		color;
	t_map	*current;
	float	k;
	float	f;

	k = ima->count_z;
	f = (ft_max_z(ima->map) - ft_min_z(ima->map));
	diff = (ft_max_z(ima->map) - ft_min_z(ima->map)) / k;
	current = ima->map;
	while (current != NULL)
	{
		color = color_difference(0xFFFFFF, 0xFF, f, (diff * current->z));
		current->color = color;
		current = current->nextx;
	}
	return ;
}

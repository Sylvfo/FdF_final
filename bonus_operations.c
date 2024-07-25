/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:18:01 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 14:09:23 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_xy(t_data *ima)
{
	t_map	*map;

	map = ima->map;
	while (map)
	{
		if (map->out == true || map->end == true)
		{
			map->xiso += ima->xmove;
			map->yiso -= ima->ymove;
		}
		map = map->nextx;
	}
}

void	ft_exit_esc(t_data *ima)
{
	mlx_destroy_image(ima->mlx_ptr, ima->img);
	mlx_destroy_window(ima->mlx_ptr, ima->mlx_win);
	ft_printf("ESC pressed.\nWindow closed\n");
	ft_free_list(&ima->map);
	free(ima);
	exit(0);
}

void	ft_delete_y(t_data *ima)
{
	int		i;
	t_map	*map;

	i = 0;
	map = ima->map;
	while (i < ima->del_y)
	{
		map->end = false;
		map = map->nexty;
		while (map->nexty != NULL && map->xbase == map->nexty->xbase)
		{
			map->end = false;
			map = map->nexty;
		}
		map->end = false;
		map = map->nexty;
		i++;
	}
}

void	ft_delete_x(t_data *ima)
{
	int		i;
	t_map	*map;

	i = 0;
	map = ima->map;
	while (i < ima->del_x && map->nextx != NULL)
	{
		while (map->nextx != NULL && map->ybase == map->nextx->ybase)
		{
			map->end = false;
			map = map->nextx;
		}
		map->end = false;
		map = map->nextx;
		i++;
	}
}

void	ft_save_color(t_map *map)
{
	while (map)
	{
		map->colorbase = map->color;
		map = map->nextx;
	}
	return ;
}

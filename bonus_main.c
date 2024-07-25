/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:34:47 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 13:45:11 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	*ima;

	map = NULL;
	ima = NULL;
	map = read_file(argc, argv[1]);
	if (!map)
		return (0);
	ima = malloc(sizeof(t_data));
	if (!ima)
		return (0);
	ima->mlx_ptr = mlx_init();
	if (ima->mlx_ptr == NULL)
		return (0);
	ima->mlx_win = mlx_new_window(ima->mlx_ptr, 2200, 1300, "fenfen");
	ima->map = map;
	ft_init_view1(ima);
	drawings_plans(ima);
	mlx_hook(ima->mlx_win, 2, 1L << 0, ft_keys_bonus, ima);
	mlx_hook(ima->mlx_win, 17, 0, ft_exit, ima);
	mlx_loop(ima->mlx_ptr);
	free (map);
	return (0);
}

void	drawings_plans(t_data *ima)
{	
	if (ima->proj == 3)
		init_view(ima, front);
	if (ima->proj == 35)
		init_view(ima, plan);
	if (ima->proj == 1)
		init_view(ima, side);
	if (ima->proj == 11)
		init_view(ima, ft_iso_30);
	if (ima->proj == 9)
		init_view(ima, ft_iso_45);
	ima->img = mlx_new_image(ima->mlx_ptr, 2200, 1300);
	ima->addr = mlx_get_data_addr(ima->img, &ima->bits_per_pixel,
			&ima->line_length, &ima->endian);
	center_pict(ima->map, 2200, 1300);
	move_xy(ima);
	draw_lines(ima);
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0);
}

void	init_view(t_data *ima, void (*view)())
{
	if (ima->newview == true)
	{
		ft_init_xyz(ima->map);
		view(ima->map);
		ima->zoom_x_y = scale(ima->map);
		ima->zoom_z = scale(ima->map);
		zoom_bonus(ima);
	}
	if (ima->z_1 == true)
		zoom_bonus(ima);
	if (ima->z_2 == true)
		zoom_zoom_z(ima);
	ft_delete_y(ima);
	ft_delete_x(ima);
	ft_colors_find(ima);
	view(ima->map);
}

void	ft_init_view1(t_data *ima)
{
	ima->proj = 11;
	ima->zoom_limit = 25;
	ima->xmove = 0;
	ima->ymove = 0;
	ima->zoom_x_y = scale(ima->map);
	ima->zoom_z = scale(ima->map);
	ima->count_x = ft_x_count(ima->map);
	ima->count_y = ft_y_count(ima->map);
	ima->count_z = ft_z_count(ima->map);
	ima->max_z = ft_max_z(ima->map);
	ima->del_x = 0;
	ima->del_y = 0;
	ima->z_1 = true;
	ima->z_2 = false;
	ima->newview = true;
	ft_save_color(ima->map);
	return ;
}

void	ft_init_xyz(t_map *map)
{
	while (map != NULL)
	{
		map->x = (float)map->xbase;
		map->y = (float)map->ybase;
		map->z = (float)map->zbase;
		map = map->nextx;
	}
	return ;
}

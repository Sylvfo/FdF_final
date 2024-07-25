/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:34:47 by sforster          #+#    #+#             */
/*   Updated: 2024/06/12 18:49:13 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	*ima;

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
	drawings(ima);
	mlx_hook(ima->mlx_win, 17, 0, ft_exit, ima);
	mlx_hook(ima->mlx_win, 2, 1L << 0, ft_keys, ima);
	mlx_loop(ima->mlx_ptr);
	free (map);
	return (0);
}

void	drawings(struct s_data *ima)
{
	float	sizezoom;

	ima->img = mlx_new_image(ima->mlx_ptr, 2200, 1300);
	ima->addr = mlx_get_data_addr(ima->img, &ima->bits_per_pixel,
			&ima->line_length, &ima->endian);
	ft_iso_30(ima->map);
	sizezoom = scale(ima->map);
	zoom(ima->map, sizezoom);
	ft_iso_30(ima->map);
	center_pict(ima->map, 2200, 1300);
	draw_lines(ima);
	mlx_put_image_to_window(ima->mlx_ptr, ima->mlx_win, ima->img, 0, 0);
}

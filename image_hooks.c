/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:24 by sforster          #+#    #+#             */
/*   Updated: 2024/06/13 13:27:47 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!x || !y)
		return ;
	if (x >= 2200)
		return ;
	if (y >= 1300)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_keys(int keycode, t_data *ima)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(ima->mlx_ptr, ima->img);
		mlx_destroy_window(ima->mlx_ptr, ima->mlx_win);
		ft_printf("ESC pressed.\nWindow closed\n");
		ft_free_list(&ima->map);
		free(ima);
		exit(0);
		return (0);
	}
	return (0);
}

int	ft_exit(t_data *ima)
{
	mlx_destroy_image(ima->mlx_ptr, ima->img);
	mlx_destroy_window(ima->mlx_ptr, ima->mlx_win);
	ft_printf("Window closed\n");
	ft_free_list(&ima->map);
	free(ima);
	exit(0);
	return (0);
}

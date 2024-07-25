/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:24 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 13:50:38 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 2200 || y < 0 || y >= 1300)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_keys_bonus(int key, t_data *ima)
{
	ft_printf("keynote: %i\n", key);
	if (key == 53)
	{
		ft_exit_esc(ima);
		return (0);
	}
	ima->newview = false;
	if (key == 1 || key == 9 || key == 11 || key == 3 || key == 35)
		ft_proj_type(ima, key);
	ima->z_1 = false;
	ima->z_2 = false;
	if (key == 69 || key == 78)
		ft_zoom_type(ima, key);
	if (key == 43 || key == 47)
		ft_zoom_z(ima, key);
	if (key == 126 || key == 125 || key == 124 || key == 123 || key == 8)
		ft_move_type(ima, key);
	if (key >= 18 && key <= 29)
		ft_colors_type(ima, key);
	if (key == 40 || key == 37)
		ft_del_type(ima, key);
	drawings_plans(ima);
	return (0);
}

void	ft_proj_type(t_data *ima, int key)
{
	ima->proj = key;
	ima->newview = true;
	ima->zoom_x_y = 1;
	ima->zoom_z = 1;
	ima->zoom_limit = 25;
	ima->xmove = 0;
	ima->ymove = 0;
	ima->zoom_z = 1;
	ima->del_y = 0;
	return ;
}

void	ft_zoom_type(t_data *ima, int key)
{	
	if (key == 78)
	{
		ima->zoom_x_y *= 0.9;
		ima->zoom_z *= 0.9;
		ima->zoom_limit--;
		ima->z_1 = true;
	}
	else if (key == 69)
	{
		ima->zoom_x_y /= 0.9;
		ima->zoom_z /= 0.9;
		ima->zoom_limit++;
		ima->z_1 = true;
	}	
	else if (ima->zoom_limit > 35 || ima->zoom_limit < 15)
	{
		ima->zoom_x_y = 1;
		ima->zoom_z = 1;
		ima->zoom_limit = 25;
	}
	return ;
}

void	ft_zoom_z(t_data *ima, int key)
{
	if (key == 43)
	{
		ima->zoom_z /= 0.9;
		ima->z_2 = true;
	}
	else if (key == 47)
	{
		ima->zoom_z *= 0.9;
		ima->z_2 = true;
	}
	return ;
}

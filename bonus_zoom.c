/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:38:11 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 14:06:55 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_bonus(t_data *ima)
{
	t_map	*current;
	float	xy;
	float	z;

	current = ima->map;
	xy = ima->zoom_x_y;
	z = ima->zoom_z;
	while (current != NULL)
	{
		if (current->end == false)
		{
			current->x = 0.0;
			current->y = 0.0;
			current->z = 0.0;
		}
		else
		{
			current->x = (float)current->xbase * xy;
			current->y = (float)current->ybase * xy;
			current->z = (float)current->zbase * z;
		}
		current = current->nextx;
	}
}

void	zoom_zoom_z(t_data *ima)
{
	t_map	*current;
	float	z;

	current = ima->map;
	z = ima->zoom_z;
	while (current != NULL)
	{
		if (current->end == false)
			current->z = 0.0;
		else
			current->z = (float)current->zbase * z;
		current = current->nextx;
	}
}

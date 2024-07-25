/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_scaling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:37:25 by sforster          #+#    #+#             */
/*   Updated: 2024/06/13 16:29:37 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	scale(t_map *map)
{
	float	x;
	float	y;

	x = (2000 / scale_x(map));
	y = (1100 / scale_y(map));
	if (x < y)
		return (x);
	return (y);
}

float	scale_x(t_map *map)
{
	t_map	*current;
	t_map	ymin;
	t_map	ymax;
	float	size_xx;	

	current = map;
	ymin.xiso = -100;
	ymax.xiso = 4000;
	while (current != NULL)
	{
		if (current->xiso > ymin.xiso && current->end == true)
		{
			ymin.xiso = current->xiso;
			ymin.yiso = current->yiso;
		}
		else if (current->xiso < ymax.xiso && current->end == true)
		{
			ymax.xiso = current->xiso;
			ymax.yiso = current->yiso;
		}
		current = current->nextx;
	}
	size_xx = sqrt(pow((ymax.xiso - ymin.xiso), 2.0)
			+ pow((ymax.yiso - ymin.yiso), 2.0));
	return (size_xx);
}

float	scale_y(t_map *map)
{
	t_map	*current;
	t_map	ymin;
	t_map	ymax;
	float	size_xx;	

	current = map;
	ymin.yiso = -100;
	ymax.yiso = 4000;
	while (current != NULL)
	{
		if (current->yiso > ymin.yiso && current->end == true)
		{
			ymin.xiso = current->xiso;
			ymin.yiso = current->yiso;
		}
		else if (current->yiso < ymax.yiso && current->end == true)
		{
			ymax.xiso = current->xiso;
			ymax.yiso = current->yiso;
		}
		current = current->nextx;
	}
	size_xx = sqrt(pow((ymax.xiso - ymin.xiso), 2.0)
			+ pow((ymax.yiso - ymin.yiso), 2.0));
	return (size_xx);
}

void	zoom(t_map *head, float z)
{
	t_map	*current;

	current = head;
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
			current->x = (float)current->x * z;
			current->y = (float)current->y * z;
			current->z = (float)current->z * z;
		}
		current = current->nextx;
	}
}

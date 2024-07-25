/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:23:05 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 14:12:27 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//fonction pour centre le dessin. 
void	center_pict(t_map *map_x, int wind_width, int wind_hgt)
{
	center_width(map_x, wind_width);
	center_height(map_x, wind_hgt);
}

void	center_width(t_map *head, int wind_width)
{
	t_map	*current;
	float	i;
	int		j;
	int		k;

	current = head;
	i = current->xiso;
	j = current->xiso;
	while (current != NULL)
	{
		if (current->xiso < i)
			i = current->xiso;
		if (current->xiso > j)
			j = current->xiso;
		current = current->nextx;
	}
	k = ((wind_width - (j - i)) / 2) + (-1 * i);
	current = head;
	while (current != NULL)
	{
		current->xiso += k;
		current = current->nextx;
	}
}

void	center_height(t_map *head, int wind_hgt)
{
	t_map	*current;
	float	i;
	float	j;
	float	k;

	current = head;
	i = current->nexty->yiso;
	j = current->nexty->yiso;
	while (current != NULL)
	{
		if (current->yiso < i && current->end == true)
			i = current->yiso;
		if (current->yiso > j && current->end == true)
			j = current->yiso;
		current = current->nextx;
	}
	k = (((wind_hgt - (j - i)) / 2) + (-1 * i));
	current = head;
	while (current != NULL)
	{
		current->yiso += k;
		current = current->nextx;
	}
}

/*
void	center_height(t_map *head, int wind_hgt)
{
	t_map	*current;
	int		i;
	int		j;
	int		k;

	current = head;
	i = current->nexty->yiso;
	j = current->nexty->yiso;
	while (current != NULL)
	{
		if (current->yiso < i && current->end == true)
			i = current->yiso;
		if (current->yiso > j && current->end == true)
			j = current->yiso;
		current = current->nextx;
	}
//	k = (((wind_hgt) / 2) + (-1 * i));
	k = (((wind_hgt - (j - i)) / 2) + (-1 * i));
	current = head;
	while (current != NULL)
	{
		current->yiso += k;
		current = current->nextx;
	}
}*/

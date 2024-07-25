/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:11:29 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 14:10:43 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_data *ima)
{
	t_map		*current;

	current = ima->map;
	while (current->nextx != NULL)
	{
		if (current->end == true && current->nextx->end == true)
		{
			if (current->out == true && current->nextx->out == true)
				draw_lines_x(ima, current);
		}
		current = current->nextx;
	}
	current = ima->map;
	while (current->nexty != NULL && current != NULL)
	{
		if (current->end == true && current->nexty->end == true)
		{
			if (current->out == true && current->nexty->out == true)
				draw_lines_y(ima, current);
		}
		current = current->nexty;
	}
	return ;
}

void	draw_lines_x(t_data *im, t_map *p)
{
	float		steps;
	float		xinc;
	float		yinc;
	int			i;
	int			color;

	i = 0;
	if (fabs((float)(p->nextx->xiso - p->xiso))
		>= fabs((float)(p->nextx->yiso - p->yiso)))
		steps = fabs((float)(p->nextx->xiso - p->xiso));
	else
		steps = fabs((float)(p->nextx->yiso - p->yiso));
	xinc = (float)(p->nextx->xiso - p->xiso) / steps;
	yinc = (float)(p->nextx->yiso - p->yiso) / steps;
	color = p->color;
	p->l1 = p->xiso;
	p->l2 = p->yiso;
	while (i <= steps)
	{
		color = color_difference(p->color, p->nextx->color, steps, i);
		my_mlx_pixel_put(im, (int)round(p->l1), (int)round(p->l2), color);
		p->l1 += xinc;
		p->l2 += yinc;
		i++;
	}
}

void	draw_lines_y(t_data *im, t_map *p)
{
	float		steps;
	float		xinc;
	float		yinc;
	int			i;
	int			color;

	i = 0;
	if (fabs((float)(p->nexty->xiso - p->xiso))
		>= fabs((float)(p->nexty->yiso - p->yiso)))
		steps = fabs((float)(p->nexty->xiso - p->xiso));
	else
		steps = fabs((float)(p->nexty->yiso - p->yiso));
	xinc = (float)(p->nexty->xiso - p->xiso) / steps;
	yinc = (float)(p->nexty->yiso - p->yiso) / steps;
	p->l1 = p->xiso;
	p->l2 = p->yiso;
	while (i <= steps)
	{
		color = color_difference(p->color, p->nexty->color, steps, i);
		my_mlx_pixel_put(im, (int)round(p->l1), (int)round(p->l2), color);
		p->l1 += xinc;
		p->l2 += yinc;
		i++;
	}
}

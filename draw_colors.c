/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:27:52 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 14:37:32 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_red(int color, int color2, int steps, float i)
{
	float		red;
	float		red2;
	float		diff_red;
	int			rd;

	rd = 0;
	red = ((color >> 16) & 0xFF);
	red2 = ((color2 >> 16) & 0xFF);
	if (red == red2 || steps == 0)
		return (red);
	if (red < red2)
	{
		diff_red = (red2 - red);
		rd = red + round((diff_red / steps) * i);
	}	
	else
	{
		diff_red = (float)(red - red2);
		rd = red - round((diff_red / steps) * i);
	}
	return (rd);
}

int	get_green(int color, int color2, int steps, float i)
{
	int		green;
	int		green2;
	float	diff_green;
	int		gr;

	gr = 0;
	green = ((color >> 8) & 0xFF);
	green2 = ((color2 >> 8) & 0xFF);
	if (green == green2 || steps == 0)
		return (green);
	if (green < green2)
	{
		diff_green = (float)(green2 + green);
		gr = green + round((diff_green / steps) * i);
	}	
	else
	{
		diff_green = (float)(green - green2);
		gr = green - round((diff_green / steps) * i);
	}
	return (gr);
}

int	get_blue(int color, int color2, int steps, float i)
{
	int		blue;
	int		blue2;
	float	diff_blue;
	int		bl;

	blue = ((color >> 0) & 0xFF);
	blue2 = ((color2 >> 0) & 0xFF);
	if (blue == blue2 || steps == 0)
		return (blue);
	if (blue < blue2)
	{
		diff_blue = (float)(blue2 - blue);
		bl = blue + round((diff_blue / steps) * i);
	}	
	else
	{
		diff_blue = (float)(blue - blue2);
		bl = blue - round((diff_blue / steps) * i);
	}
	return (bl);
}

int	color_difference(int color, int color2, int steps, int i)
{
	int		red;
	int		green;
	int		blue;
	double	dist;

	red = get_red(color, color2, steps, i);
	green = get_green(color, color2, steps, i);
	blue = get_blue(color, color2, steps, i);
	dist = (red * 65536 + green * 256 + blue);
	return ((int)dist);
}

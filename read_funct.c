/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:38:36 by sforster          #+#    #+#             */
/*   Updated: 2024/06/12 14:50:03 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_register_line(t_map **head, char *line, int y)
{
	char			**spline;
	int				x;
	int				col;

	x = 0;
	spline = ft_split(line, ' ');
	while (x < (int)ft_count_x(line))
	{	
		pushfront_base(head, x, y, ft_atoi(&spline[x][0]));
		col = ft_get_color(&spline[x][0]);
		access_coord(head, col);
		x++;
		col++;
	}
	ft_free_tab(spline);
	pushfront_neutral(head, x, y);
}

int	ft_get_color(char *splinette)
{
	int		i;
	char	*col;
	int		j;

	j = 0;
	i = 0;
	while (splinette[i] && splinette[i] != ',')
		i++;
	if (splinette[i] == ',')
	{
		i += 3;
		col = malloc(9 * sizeof(char));
		while (splinette[i])
		{
			col[j] = splinette[i];
			j++;
			i++;
		}
		col[j] = '\0';
		i = ft_atoi_x(col);
		free (col);
		return (i);
	}
	return (0xffffff);
}

size_t	ft_count_x(char *str)
{
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	i = 0;
	j = 1;
	if (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
			j++;
		i++;
	}
	if (str[i - 1] != ' ')
		j++;
	return (j - 1);
}

char	*ft_clean_line(char *l)
{
	char	*nl;
	char	*tmp;
	int		i;
	int		j;

	if (l == NULL)
		return (NULL);
	if (l[0] == '\0' || l[0] == '\n')
		return (NULL);
	i = 0;
	tmp = l;
	nl = malloc((ft_strlen(tmp) + 1) * sizeof(char));
	j = 0;
	while (tmp[i] != 10 && tmp[i])
	{
		while (tmp[i] == ' ' && tmp[i + 1] == ' ')
			i++;
		nl[j] = tmp[i];
		i++;
		j++;
	}
	nl[j] = '\0';
	free(tmp);
	return (nl);
}

void	ft_set_next_y(t_map **head)
{
	t_map	*cur_x;
	t_map	*cur_y;

	cur_x = *head;
	cur_y = *head;
	while (cur_y->ybase == cur_x->ybase && cur_x != NULL)
		cur_x = cur_x->nextx;
	while (cur_x != NULL)
	{
		cur_y->nexty = cur_x;
		cur_x = cur_x->nextx;
		cur_y = cur_y->nextx;
	}
	cur_x = *head;
	cur_y = *head;
	cur_y = cur_y->nextx;
	while (cur_x->nextx != NULL)
	{
		if (cur_x->nexty == NULL)
		{
			cur_x->nexty = cur_y;
			cur_y = cur_y->nextx;
		}
		cur_x = cur_x->nextx;
	}
}

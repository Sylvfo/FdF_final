/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_chained_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:37:45 by sforster          #+#    #+#             */
/*   Updated: 2024/06/13 19:28:48 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*creatdata_base(int xbase, int ybase, int zbase)
{
	t_map	*newnode;

	newnode = malloc(sizeof(t_map));
	if (newnode == NULL)
	{
		ft_printf("erreur avec malloc\n");
		return (NULL);
	}
	newnode->xbase = xbase;
	newnode->ybase = ybase;
	newnode->zbase = zbase;
	newnode->color = 0xffffff;
	newnode->xiso = 0;
	newnode->yiso = 0;
	newnode->l1 = 0;
	newnode->l2 = 0;
	newnode->x = xbase;
	newnode->y = ybase;
	newnode->z = zbase;
	newnode->out = true;
	newnode->end = true;
	newnode->nextx = NULL;
	newnode->nexty = NULL;
	return (newnode);
}

void	pushfront_base(t_map **head, int xbase, int ybase, int zbase)
{
	t_map	*newnode;

	newnode = creatdata_base(xbase, ybase, zbase);
	if (*head == NULL)
	{
		*head = newnode;
		return ;
	}
	newnode->nextx = *head;
	newnode->nexty = NULL;
	*head = newnode;
}

void	pushfront_neutral(t_map **head, int xbase, int ybase)
{
	t_map	*newnode;

	newnode = creatdata_neutral(xbase, ybase);
	if (newnode == NULL)
	{
		ft_printf("erreur avec malloc\n");
		return ;
	}
	if (*head == NULL)
	{
		*head = newnode;
		return ;
	}
	newnode->nextx = *head;
	*head = newnode;
}

t_map	*creatdata_neutral(int xbase, int ybase)
{
	t_map	*newnode;

	newnode = ft_calloc(1, sizeof(t_map));
	if (!newnode && ft_printf("erreur avec malloc\n"))
		return (NULL);
	newnode->xbase = xbase;
	newnode->ybase = ybase;
	newnode->end = false;
	return (newnode);
}

void	access_coord(t_map **st, int col)
{
	t_map	*current;

	current = *st;
	current->color = col;
}

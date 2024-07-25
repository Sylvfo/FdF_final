/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:36:15 by sforster          #+#    #+#             */
/*   Updated: 2024/06/12 14:57:06 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi_x(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0x0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 16) + (str[i] - 48);
			i++;
		}
		else if (str[i] >= 'a' && str[i] <= 'f')
		{
			result = (result * 16) + (str[i] - 87);
			i++;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			result = (result * 16) + (str[i] - 55);
			i++;
		}
	}
	return (result);
}

char	*ft_get_map(char *str)
{
	char	*st;
	int		i;
	int		t;

	t = ft_strlen(str);
	st = malloc((7 + t + 1) * sizeof(char));
	st[0] = '.';
	st[1] = '/';
	st[2] = 'm';
	st[3] = 'a';
	st[4] = 'p';
	st[5] = 's';
	st[6] = '/';
	i = 0;
	while (i < t)
	{
		st[i + 7] = str[i];
		i++;
	}
	st[i + 7] = '\0';
	return (st);
}

void	ft_free_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i] != NULL)
			free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_list(t_map **head)
{
	t_map	*current;
	t_map	*tmp;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		current = current->nextx;
		free(tmp);
	}
	*head = NULL;
}

void	printlist_coord(t_map *head)
{
	t_map	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("xbase: %i, ybase: %i, zbase: %i, \n", current->xbase,
			current->ybase, current->zbase);
		current = current->nextx;
	}
}

/*
void	ft_free_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '\0')
				free(&tab[i][j]);
			j++;
		}
		if (tab[i] != NULL)
			free(tab[i]);
		i++;
	}
	free(tab);
}
*/
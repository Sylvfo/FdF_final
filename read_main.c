/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:33:11 by sforster          #+#    #+#             */
/*   Updated: 2024/06/12 14:57:14 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*read_file(int argc, char *argv)
{
	int		fd;
	char	*tomap;
	t_map	*map;

	if (check_arg(argc) == false || check_extention(argv) == false)
		return (NULL);
	tomap = ft_get_map(argv);
	fd = open(tomap, O_RDONLY);
	if (check_fd(fd, tomap) == false)
	{
		return (NULL);
	}
	free (tomap);
	map = NULL;
	map = read_map(fd);
	if (check_map(map) == false)
		return (NULL);
	ft_set_next_y(&map);
	return (map);
}

t_map	*read_map(int fd)
{
	t_map	*map;
	char	*line;
	size_t	y;
	size_t	colonnes;

	line = ft_clean_line(get_next_line(fd));
	if (!line)
		return (NULL);
	colonnes = ft_count_x(line);
	map = NULL;
	init_chained_list_neutral(&map, colonnes);
	y = 1;
	while (line != NULL)
	{
		if (check_size(&map, line, colonnes) == 0)
			return (map);
		ft_register_line(&map, line, y);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		line = ft_clean_line(line);
		y++;
	}
	return (map);
}

int	check_size(t_map **head, char *li, size_t colonnes)
{
	if ((int)ft_count_x(li) == 0)
		return (1);
	if (ft_count_x(li) != colonnes)
	{
		ft_printf("maps not rectangular\n");
		free (li);
		ft_free_list(head);
		return (0);
	}
	return (1);
}

void	init_chained_list_neutral(t_map **head, int nb_col)
{	
	nb_col += 1;
	while (nb_col > 0)
	{
		pushfront_neutral(head, nb_col, 0);
		nb_col--;
	}
	return ;
}

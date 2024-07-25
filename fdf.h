/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:32:30 by sforster          #+#    #+#             */
/*   Updated: 2024/06/14 14:32:14 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "librairies/printf/ft_printf.h"
# include "librairies/libft/libft.h"
# include "librairies/minilibx_opengl_20191021/mlx.h"
# include <math.h>
# include <stdbool.h>

typedef struct s_map {
	int				xbase;
	int				ybase;
	int				zbase;
	float			x;
	float			y;
	float			z;
	int				color;
	int				colorbase;
	bool			end;
	struct s_map	*nextx;
	struct s_map	*nexty;
	float			xiso;
	float			yiso;
	float			l1;
	float			l2;
	bool			out;
}	t_map;

typedef struct s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_map			*map;
	void			*mlx_ptr;
	void			*mlx_win;
	int				proj;
	bool			newview;
	int				xmove;
	int				ymove;
	int				color;
	int				del_y;
	int				del_x;
	int				count_x;
	int				count_y;
	int				count_z;
	int				max_z;
	int				min_z;
	bool			z_1;
	bool			z_2;
	int				zoom_limit;
	float			zoom_z;
	float			zoom_x_y;
}	t_data;

// main.c
void		drawings(t_data *ima);

//////////////////////////////////////////////////
// DRAW

// draw_lines.c
void		draw_lines_x(t_data *im, t_map *p);
void		draw_lines_y(t_data *im, struct s_map *p);
void		draw_lines(t_data *ima);
void		draw_lines2(t_data *ima);
bool		min_max(t_map *current);

//draw_colors.c
int			color_difference(int color, int color2, int steps, int i);
int			get_red(int color, int color2, int steps, float i);
int			get_green(int color, int color2, int steps, float i);
int			get_blue(int color, int color2, int steps, float i);

// draw 3d.c
void		ft_iso_30(t_map *carte);
void		ft_iso_45(t_map *carte);

//////////////////////////////////////////////////
// READ MAPS

// read_main.c
t_map		*read_file(int argc, char *argv);
t_map		*read_map(int fd);
int			ft_check_numbers(t_map **head, char *line);
int			check_size(t_map **head, char *line, size_t colonnes);
void		init_chained_list_neutral(t_map **head, int nb_col);

// read_check_files.c
bool		check_arg(int argc);
bool		check_extention(char *str);
bool		check_fd(int fd, char *tomap);
bool		check_map(t_map *map);

// read_utils.c
int			ft_atoi_x(const char *str);
char		*ft_get_map(char *str);
void		ft_free_list(t_map **head);
void		ft_free_tab(char **tab);
void		printlist_coord(t_map *head);

// read_funct.c
char		*ft_clean_line(char *l);
size_t		ft_count_x(char *str);
void		ft_register_line(t_map **head, char *line, int y);
int			ft_get_color(char *splinette);
void		ft_set_next_y(t_map **head);

// read_chained_list.c
t_map		*creatdata_base(int xbase, int ybase, int zbase);
void		pushfront_base(t_map **head, int xbase, int ybase, int zbase);
void		access_coord(t_map **st, int col);
void		pushfront_neutral(t_map **head, int xbase, int ybase);
t_map		*creatdata_neutral(int xbase, int ybase);

//////////////////////////////////////////////////
// IMAGE

// image_center.c
void		center_pict(t_map *map_x, int wind_width, int wind_hgt);
void		center_width(t_map *head, int wind_width);
void		center_height(t_map *head, int wind_hgt);

// image_scaling.c
float		scale(t_map *map_x);
void		zoom(t_map *head, float z);
float		scale_x(t_map *map);
float		scale_y(t_map *map);

//image_hooks.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_exit(t_data *ima);
int			ft_keys(int keycode, t_data *ima);
int			ft_keys_proj(int keycode, t_data *ima);

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
// BONUS

// main
void		drawings_plans(t_data *ima);
void		init_view(t_data *ima, void (*view)());
void		ft_init_xyz(t_map *map);
void		ft_init_view1(t_data *ima);

// bonus_hooks.c
int			ft_keys_bonus(int key, t_data *ima);
void		ft_proj_type(t_data *ima, int key);
void		ft_zoom_type(t_data *ima, int key);
void		ft_zoom_z(t_data *ima, int key);

// bonus_hooks_2.c
void		ft_move_type(t_data *ima, int key);
void		ft_colors_type(t_data *ima, int key);
void		ft_blue_green(t_data *ima);
void		ft_del_type(t_data *ima, int key);

// bonus_plan.c
void		plan(t_map *map);
void		front(t_map *map);
void		side(t_map *map);

// bonus-utils.c
int			ft_x_count(t_map *map);
int			ft_y_count(t_map *map);
int			ft_max_z(t_map *map);
int			ft_min_z(t_map *map);
int			ft_z_count(t_map *map);

// bonus operations
void		move_xy(t_data *ima);
void		ft_delete_y(t_data *ima);
void		ft_delete_x(t_data *ima);
void		ft_exit_esc(t_data *ima);
void		ft_save_color(t_map *map);

// colors
void		ft_colors_find(t_data *ima);
void		ft_white(t_map *map);
void		ft_col_base(t_map *map);
void		ft_blue(t_map *map);
void		ft_light_on_ice(t_data *ima);

// zoom
void		zoom_bonus(t_data *ima);
void		zoom_zoom_z(t_data *ima);

#endif
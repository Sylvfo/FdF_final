NAME			= fdf
SRCS			= 	main.c \
					read_main.c read_check_file.c read_chained_list.c\
					read_funct.c	read_utils.c\
					draw_colors.c	draw_lines.c	draw_3d.c\
					image_scaling.c image_center.c image_hooks.c\

SRCSBON			= 	bonus_main.c \
					read_main.c read_check_file.c read_chained_list.c\
					read_funct.c	read_utils.c\
					draw_colors.c	draw_lines.c	draw_3d.c\
					image_scaling.c image_center.c\
					bonus_hooks.c	bonus_hooks_2.c	bonus_plans.c\
					bonus_zoom.c bonus_utils.c bonus_operations.c\
					bonus_color.c \

OBJ_DIR 		= obj
OBJ_DIR 		= obj
FLAGS			= -Wall -Wextra -Werror
CC				= gcc
RM				= rm -f

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJB = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCSBON))

PRINTF_DIR		= librairies/printf
PRINTF			= ./${PRINTF_DIR}/libftprintf.a
LIBFT_DIR		= librairies/libft
LIBFT 			= ./${LIBFT_DIR}/libft.a
MINILIBX_DIR	= librairies/minilibx_opengl_20191021
MINILIBX		= ./${MINILIBX_DIR}/libmlx.a

all: $(NAME)

$(NAME): ${OBJ}
		@(make -s -C ${PRINTF_DIR})
		@(make -s -C ${LIBFT_DIR})
		@(make -s -C ${MINILIBX_DIR})
		@(${CC} ${FLAGS} -o $@ $^ ${PRINTF} ${LIBFT} ${MINILIBX} -framework OpenGL -framework AppKit)

$(OBJ_DIR)/%.o: %.c
		@(mkdir -p $(OBJ_DIR))
		@(${CC} ${FLAGS} -c $< -o $@)

bonus: fdf_bonus

fdf_bonus: ${OBJB}
		@(make -s -C ${PRINTF_DIR})
		@(make -s -C ${LIBFT_DIR})
		@(make -s -C ${MINILIBX_DIR})
		@(${CC} ${FLAGS} -o $@ $^ ${PRINTF} ${LIBFT} ${MINILIBX} -framework OpenGL -framework AppKit)

$(OBJB_DIR)/%.o: %.c
		mkdir -p $(OBJB_DIR)
		${CC} ${FLAGS} -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)
		make clean -C ${PRINTF_DIR}
		make clean -C ${LIBFT_DIR}
		make clean -C ${MINILIBX_DIR}
		$(RM) $(OBJB)
		$(RM) $(OBJ)

fclean:		clean
		make fclean -C ${PRINTF_DIR}
		make fclean -C ${LIBFT_DIR}
		make clean -C ${MINILIBX_DIR}
		$(RM) $(NAME)
		$(RM) fdf_bonus
 
re:			fclean	all

.PHONY:		all re clean fclean
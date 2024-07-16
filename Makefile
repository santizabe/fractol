NAME	= fractol
BONUS	= fractol_bonus
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
CC		= clang
LIBMLX	= ./MLX42
FT_PRINTF = ./ft_printf/libftprintf.a
MLX_42	= MLX42/libmlx42.a

HEADERS	:= -I $(LIBMLX)/include/MLX42
LIBS	:= $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= args_checker.c calc_coordenates.c change_color.c main.c \
			scroll_recalc.c arrow_manager.c calc_h_v_lines.c ft_atod.c \
			ft_isdouble.c misc.c zoom_manager.c color_pixel.c
B_SRC	:= args_checker_bonus.c main.c calc_coor_bonus.c change_color.c \
			scroll_recalc.c arrow_manager.c calc_h_v_lines.c ft_atod.c \
			ft_isdouble.c misc.c zoom_manager.c color_pixel.c
OBJS	:= ${SRCS:.c=.o}
B_OBJS	:= ${B_SRC:.c=.o}

all: $(NAME)

$(MLX_42):
	@make -s -C $(LIBMLX)

$(FT_PRINTF):
	@make -s bonus -C ft_printf

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

bonus: $(BONUS)

$(BONUS): $(MLX_42) $(FT_PRINTF) $(B_OBJS)
	@$(CC) $(B_OBJS) $(LIBS) $(HEADERS) $(FT_PRINTF) -o $(BONUS)

$(NAME): $(MLX_42) $(FT_PRINTF) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(FT_PRINTF) -o $(NAME)

clean:
	@rm -rf *.o
	@make clean -s -C MLX42
	@make clean -s -C ft_printf

fclean:
	@rm -rf *.o
	@rm -rf $(NAME)
	@make fclean -s -C ft_printf
	@make fclean -s -C MLX42

bfclean:
	@rm -rf *.o
	@rm -rf $(BONUS)
	@make fclean -s -C ft_printf
	@make fclean -s -C MLX42

re: fclean all

reb: bfclean bonus

.PHONY: all clean fclean re libmlx bonus bfclean
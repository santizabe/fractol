NAME	= fractol
BONUS	= fractol_bonus
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -O3 -ffast-math
LIBMLX	= ./MLX42
FT_PRINTF = ft_printf/libftprintf.a
MLX_42	= MLX42/libmlx42.a

HEADERS	:= -I $(LIBMLX)/include/MLX42 -I include/ -I ft_printf/

LIBS	:= $(MLX_42) -ldl -lglfw -pthread -lm
SRCS	:= args_checker.c calc_coordenates.c change_color.c main.c \
			scroll_recalc.c arrow_manager.c calc_h_v_lines.c ft_atod.c \
			ft_isdouble.c misc.c zoom_manager.c color_pixel.c
B_SRC	:= args_checker_bonus.c main.c calc_coor_bonus.c change_color.c \
			scroll_recalc.c arrow_manager.c calc_h_v_lines.c ft_atod.c \
			ft_isdouble.c misc.c zoom_manager.c color_pixel.c

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

B_OBJS = $(addprefix $(OBJ_DIR)/, $(B_SRC:%.c=%.o))

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) ${CFLAGS} ${HEADERS} -c $< -o $@

all: $(NAME)

$(MLX_42):
	@make -s -C $(LIBMLX) -j4

$(FT_PRINTF):
	@make -s bonus -C ft_printf

bonus: fclean $(BONUS)

$(BONUS): $(MLX_42) $(FT_PRINTF) $(B_OBJS)
	@$(CC) $(B_OBJS) $(LIBS) $(HEADERS) $(FT_PRINTF) -o $(BONUS)

$(NAME): $(MLX_42) $(FT_PRINTF) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(FT_PRINTF) -o $(NAME)

clean:
	@rm -rf obj
	@make clean -sC $(LIBMLX)
	@make clean -sC ft_printf

fclean:
	@rm -rf obj
	@rm -rf $(NAME)
	@rm -rf $(MLX_42)
	@make fclean -s -C ft_printf

bfclean:
	@rm -rf obj
	@rm -rf $(BONUS)
	@rm -rf $(MLX_42)
	@make fclean -s -C ft_printf

re: fclean all

reb: bfclean bonus

.PHONY: all clean fclean re libmlx bonus bfclean

NAME	= fractol
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
CC		= clang
LIBMLX	= ./MLX42
FT_PRINTF = ./ft_printf/libftprintf.a

HEADERS	:= -I $(LIBMLX)/include/MLX42
LIBS	:= $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find . -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx printf $(NAME)

libmlx:
	@make -C $(LIBMLX)

printf:
	@make bonus -C ft_printf

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(FT_PRINTF) -o $(NAME)

clean:
	@rm -rf *.o
	@make clean -C MLX42
	@make clean -C ft_printf

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ft_printf
	@make fclean -C MLX42

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
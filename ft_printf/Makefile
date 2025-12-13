NAME = libftprintf.a

FLAGS = -Werror -Wextra -Wall

SRC = check_format.c digit_handler.c handle_conversion.c \
	  hex_handler.c set_flags.c unsigned_handler.c \
	  check_optional.c ft_printf_utils.c handle_error.c \
	  pointer_handler.c strings_handler.c ft_printf_bonus.c

B_SRC = check_format.c digit_handler.c handle_conversion.c \
		hex_handler.c set_flags.c unsigned_handler.c \
		check_optional.c ft_printf_utils.c handle_error.c \
		pointer_handler.c strings_handler.c ft_printf_bonus.c 

OBJ = $(SRC:c=o)

B_OBJ = $(B_SRC:c=o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)

bonus: $(B_OBJ)
	@make -C libft
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(B_OBJ)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME);

re: fclean all

.PHONY: clean fclean re all
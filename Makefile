NAME= push_swap
CC= cc
CFLAGS= -Wall -Wextra -Werror -g
LIBFT= lib/libft/libft.a
PRINTF= lib/ft_printf/libftprintf.a
SRC= src/main.c \
	 src/ps_stack_utils.c \
	 src/ps_utils.c \
	 src/ps_insert_stacks.c \
	 src/ps_op0.c \
	 src/ps_op1.c \
	 src/ps_op2.c \
	 src/ps_op3.c \
	 src/sort_stack.c \
	 src/radix_sort.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "\033[32m✓ [ PUSH_SWAP ] built successfully\033[0m"

$(LIBFT):
	make -C lib/libft/

$(PRINTF):
	make -C lib/ft_printf/

clean:
	@rm -rf $(OBJ)
	@echo "\033[31m✓ [ PUSH_SWAP ] objects removed\033[0m"
	@make -C lib/libft/ clean
	@make -C lib/ft_printf/ clean

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m✓ [ PUSH_SWAP ] removed\033[0m --> $(NAME)"
	@rm -rf $(LIBFT)
	@rm -rf $(PRINTF)

re: fclean all

.PHONY: all lib re clean fclean

NAME= push_swap
CC= cc
CFLAGS= -Wall -Wextra -Werror -g
LIBFT= lib/libft/libft.a
SRC= src/main.c \
	 src/ps_stack_utils.c \
	 src/ps_utils.c \
	 src/ps_insert_stacks.c \
	 src/index_stack.c \
	 src/ps_op0.c \
	 src/ps_op1.c \
	 src/ps_op2.c \
	 src/ps_op3.c \

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C lib/libft/

clean:
	rm -rf $(OBJ)
	make -C lib/libft/ clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all lib re clean fclean

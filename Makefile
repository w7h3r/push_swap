NAME= push_swap
CC= cc
CFLAGS= -Wall -Wextra -Werror -g
LIBFT= lib/libft/libft.a
SRC= src/main.c \
	 src/push_swap.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C lib/libft/

clean:
	rm -rf $(OBJ)
	make -C lib/libft/ clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all lib re clean fclean

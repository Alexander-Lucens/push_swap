NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

OPERATORS = ./operators/swap.c ./operators/push.c ./operators/rotate.c ./operators/rotate_reverse.c

HELPERS = ./helpers/for_main.c ./helpers/ft_addfront.c ./helpers/ft_append.c ./helpers/ft_atoi.c\
			./helpers/ft_node_clear.c ./helpers/ft_node_list_len.c ./helpers/ft_split.c

SORTING = ./sorting/algorithms.c ./sorting/check_solution.c

SRC = $(OPERATORS) $(HELPERS) $(SORTING) ./pre_checker.c ./main.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)
LIBC = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	clean

ref: fclean all
	rm -f $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re
NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = ./operators/ft_numlistlen.c ./operators/ft_sublist.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)
LIBC = ar rcs


all: $(NAME)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)
	chmod 777 *.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

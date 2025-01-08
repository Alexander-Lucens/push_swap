NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

OPERATORS = \
    ./operators/swap.c \
    ./operators/push.c \
    ./operators/rotate.c \
    ./operators/rotate_reverse.c

HELPERS = \
    ./helpers/for_main.c \
    ./helpers/ft_addfront.c \
    ./helpers/ft_append.c \
    ./helpers/ft_atoi.c \
    ./helpers/ft_node_clear.c \
    ./helpers/ft_node_list_len.c \
    ./helpers/ft_split.c

SORTING = \
    ./sorting/algorithms.c \
    ./sorting/solution.c \
    ./sorting/lucens.c \
    ./sorting/manipulations.c \
    ./indexing.c

GNL = \
    ./gnl/get_next_line.c \
    ./gnl/get_next_line_utils.c

BONUS_FILES = \
    $(OPERATORS) \
    $(HELPERS) \
    $(SORTING) \
    $(GNL) \
    ./checker.c \
    ./ps_main.c

MANDATORY_FILES = \
    $(OPERATORS) \
    $(HELPERS) \
    $(SORTING) \
    ./ps_main.c \
    ./main.c

OBJ = $(MANDATORY_FILES:.c=.o)
BONUS_OBJ = $(BONUS_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	    $(CC) $(CFLAGS) -o $(NAME) $(OBJ) 

bonus: $(BONUS_OBJ)
	    $(CC) $(CFLAGS) -o $(CHECKER) $(BONUS_OBJ)

clean:
	    rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	    rm -f $(NAME) $(CHECKER)

re: fclean all bonus
	    rm -f $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 20:10:00 by akuzmin           #+#    #+#              #
#    Updated: 2025/09/10 10:26:29 by akuzmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap
CHECKER     := checker

# **************************************************************************** #

OPERATORS   := ./operators/swap.c \
			   ./operators/push.c \
			   ./operators/rotate.c \
			   ./operators/rotate_reverse.c

HELPERS     := ./helpers/for_main.c \
			   ./helpers/ft_addfront.c \
			   ./helpers/ft_append.c \
			   ./helpers/ft_atoi.c \
			   ./helpers/ft_node_clear.c \
			   ./helpers/ft_node_list_len.c \
			   ./helpers/ft_split.c

SORTING     := ./sorting/algorithms.c \
			   ./sorting/solution.c \
			   ./sorting/engine.c \
			   ./sorting/manipulations.c \
			   ./indexing.c

GNL         := ./gnl/get_next_line.c \
			   ./gnl/get_next_line_utils.c

BONUS_SRCS  := $(OPERATORS) $(HELPERS) $(SORTING) $(GNL) ./checker.c ./ps_main.c

MAND_SRCS   := $(OPERATORS) $(HELPERS) $(SORTING) ./ps_main.c ./main.c

# **************************************************************************** #

CC          := cc

CFLAGS      := -Wall -Wextra -Werror

RM          := rm -rf

OBJDIR      := objs

MAND_OBJS   := $(MAND_SRCS:%.c=$(OBJDIR)/%.o)

BONUS_OBJS  := $(BONUS_SRCS:%.c=$(OBJDIR)/%.o)

# **************************************************************************** #

all: $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MAND_OBJS)
	@$(CC) $(CFLAGS) $(MAND_OBJS) -o $(NAME)
	@echo "Creating program $(NAME)."

bonus: $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -D CHECKER_MODE $(BONUS_OBJS) -o $(CHECKER)
	@echo "Creating program $(CHECKER)."

clean:
	@$(RM) $(OBJDIR)
	@echo "Deleting object files."

fclean: clean
	@$(RM) $(NAME) $(CHECKER)
	@echo "Deleting executables."

re: fclean all bonus

.PHONY: all re clean fclean bonus
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:17:53 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/09 14:23:31 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_rotations(char *line, t_stack *stack)
{
	if (!ft_strcmp(line, "ra"))
		rotate(&stack->a);
	else if (!ft_strcmp(line, "rb"))
		rotate(&stack->b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(&stack->a);
		rotate(&stack->b);
	}
	else if (!ft_strcmp(line, "rra"))
		reverse_rotate(&stack->a);
	else if (!ft_strcmp(line, "rrb"))
		reverse_rotate(&stack->b);
	else if (!ft_strcmp(line, "rrr"))
	{
		reverse_rotate(&stack->a);
		reverse_rotate(&stack->b);
	}
	else
		return (0);
	return (1);
}

int	execute_operation(char *line, t_stack *stack)
{
	if (!ft_strcmp(line, "sa"))
		swap(&stack->a);
	else if (!ft_strcmp(line, "sb"))
		swap(&stack->b);
	else if (!ft_strcmp(line, "pa"))
		push_a(stack);
	else if (!ft_strcmp(line, "pb"))
		push_b(stack);
	else
		return (execute_rotations(line, stack));
	return (1);
}

void	execute_checker(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (execute_operation(trim_newline(line), stack) == 0)
		{
			free(line);
			return (error());
		}
		free(line);
		line = get_next_line(0);
	}
	if (check_order(stack->a) && !stack->b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	char		**split;
	t_stack		stack;

	stack.a = NULL;
	stack.b = NULL;
	if (ac < 2)
		return (-1);
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (-1);
		stack.a = process_args(split);
		free_split(split);
	}
	else
		stack.a = process_args(av + 1);
	if (!stack.a || check_duplications(stack.a))
		return (ft_node_clear(&stack.a), -1);
	index_stack(&stack);
	execute_checker(&stack);
	ft_node_clear(&stack.a);
	ft_node_clear(&stack.b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:17:53 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 23:17:26 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static char	*trim_newline(char *dest)
{
	int	i;

	i = 0;
	while (dest && dest[i])
	{
		if (dest[i] == '\n')
		{
			dest[i] = '\0';
			break ;
		}
		i++;
	}
	return (dest);
}

int	execute_operation(char *line, t_stack *stack)
{
	if (!ft_strcmp(line, "sa"))
		sa(stack);
	else if (!ft_strcmp(line, "sb"))
		sb(stack);
	else if (!ft_strcmp(line, "ss"))
		ss(stack);
	else if (!ft_strcmp(line, "pa"))
		pa(stack);
	else if (!ft_strcmp(line, "pb"))
		pb(stack);
	else if (!ft_strcmp(line, "ra"))
		ra(stack);
	else if (!ft_strcmp(line, "rb"))
		rb(stack);
	else if (!ft_strcmp(line, "rr"))
		rr(stack);
	else if (!ft_strcmp(line, "rra"))
		rra(stack);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack);
	else if (!ft_strcmp(line, "rrr"))
		rrr(stack);
	else
		return (0);
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

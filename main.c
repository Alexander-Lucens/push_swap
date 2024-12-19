/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2024/12/19 20:37:16 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_list	*init_node_list(char *str, size_t i)
{
	t_node_list	*node;
	long long	number;

	if (!is_number(str))
		return (NULL);
	node = malloc(sizeof(t_node_list));
	if (!node)
		return (NULL);
	number = ft_atoi(str);
	if (number > 2147483647 || number < -2147483648)
		return (NULL);
	node->number = number;
	node->index = 0;
	node->previou = NULL;
	node->next = NULL;
	return (node);
}

t_node_list	*process_args(char **args)
{
	t_node_list	*list;
	t_node_list	*node;
	size_t		i;

	i = 0;
	list = NULL;
	while (args[i])
	{
		node = init_node_list(args[i], i);
		if (!node)
			return (ft_node_clear(&list), error(), NULL);
		ft_append(&list, node);
		i++;
	}
	return (list);
}

/**
 * DO NOT FORGOT DELETE THIS FUNCTION
 * print list for debug
 */

#include <stdio.h>
void print_list(t_stack *stack)
{
	t_node_list *temp = stack->a;
	t_node_list *temp2 = stack->b;

	while (temp || temp2)
	{
		if (temp)
		{
			printf("%d ", temp->number);
			temp = temp->next;
		}
		else
			printf("  ");
		if (temp2)
		{
			printf("%d\n", temp2->number);
			temp2 = temp2->next;
		}
		else
			printf("\n");
	}
	printf("- -\n%s\n", "a b");
}

int	main(int ac, char **av)
{
	char		**split;
	t_node_list	*list;
	t_stack		stack;

	list = NULL;
	if (ac < 2)
		return (error(), -1);
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (error(), -1);
		list = process_args(split);
		free_split(split);
	}
	else
		list = process_args(av + 1);
	if (!list || check_duplications(list))
		return (ft_node_clear(&list), error(), -1);
	stack.a = list;
	stack.b = NULL;
	// print_list(&stack);
	solution(&stack);
	// print_list(&stack);
	ft_node_clear(&stack.a);
    ft_node_clear(&stack.b);
	return (0);
}
// Command to generate 100 randome numbers between -100 and 100:
// shuf -i 0-1000 -n 100 | tr '\n' ' '
// gshuf -i 0-1000 -n 100 | tr '\n' ' '  		// for mac

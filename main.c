/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/09 14:28:43 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char		**split;
	t_stack		stack;

	stack.a = NULL;
	stack.b = NULL;
	if (ac < 2)
		return (error(), -1);
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (error(), -1);
		stack.a = process_args(split);
		free_split(split);
	}
	else
		stack.a = process_args(av + 1);
	if (!stack.a || check_duplications(stack.a))
		return (ft_node_clear(&stack.a), error(), -1);
	index_stack(&stack);
	solution(&stack);
	ft_node_clear(&stack.a);
	ft_node_clear(&stack.b);
	return (0);
}

/**
 * Command to generate 100 randome numbers between 0 and 1000:
 *  
 * shuf -i 0-1000 -n 100 | tr '\n' ' '
 * ARG=$(gshuf -i 0-1000 -n 100 | tr '\n' ' '); ./checker $ARG
 * ARG=$(gshuf -i 0-1000 -n 500 | tr '\n' ' '); ./checker $ARG
 * ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
 * ARG=$(shuf -i 0-1000 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
 * 
 * gshuf -i 0-1000 -n 100 | tr '\n' ' '  		// for mac
 * ARG=$(gshuf -i 0-1000 -n 100 | tr '\n' ' '); ./checker $ARG
 * ARG=$(gshuf -i 0-1000 -n 500 | tr '\n' ' '); ./checker $ARG
 * ARG=$(gshuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG
 * ARG=$(gshuf -i 0-1000 -n 500 | tr '\n' ' '); ./push_swap $ARG
 */

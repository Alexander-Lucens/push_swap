/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 21:58:54 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node_list **stack)
{
	t_node_list	*first;
	t_node_list	*second;

	if (ft_node_list_len(*stack) > 1)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->next = first;
		second->prev = NULL;
		first->prev = second;
		*stack = second;
	}
}

void	sa(t_stack *stack)
{
	swap(&stack->a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap(&stack->b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	write(1, "ss\n", 3);
}

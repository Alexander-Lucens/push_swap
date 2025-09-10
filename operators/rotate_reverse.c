/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/09 14:05:08 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_node_list **stack)
{
	t_node_list	*current;
	t_node_list	*prev;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	current = *stack;
	prev = NULL;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
	current->prev = NULL;
}

void	rra(t_stack *stack)
{
	reverse_rotate(&stack->a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(&stack->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	reverse_rotate(&stack->b);
	reverse_rotate(&stack->a);
	write(1, "rrr\n", 4);
}

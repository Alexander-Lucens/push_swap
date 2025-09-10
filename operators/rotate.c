/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/09 14:05:03 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node_list	**stack)
{
	t_node_list	*first;
	t_node_list	*last;

	if (ft_node_list_len(*stack) > 1)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		*stack = first->next;
		(*stack)->prev = NULL;
		first->next = NULL;
		last->next = first;
		first->prev = last;
	}
}

void	ra(t_stack *stack)
{
	rotate(&stack->a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	rotate(&stack->b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	write(1, "rr\n", 3);
}

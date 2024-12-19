/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2024/12/18 21:29:36 by akuzmin          ###   ########.fr       */
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
            second->next->previou = first;
        second->next = first;
        second->previou = NULL;
        first->previou = second;
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

/*
void	sa(t_stack *stack)
{
	t_node_list	*first;
	t_node_list	*second;

	if (ft_node_list_len(stack->a) > 1)
	{
		first = stack->a;
		second = stack->a->next;
		first->next = second->next;
		if (second->next)
			second->next->previou = first;
		second->next = first;
		second->previou = NULL;
		first->previou = second;
		stack->a = second;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	t_node_list	*first;
	t_node_list	*second;

	if (ft_node_list_len(stack->b) > 1)
	{
		first = stack->b;
		second = stack->b->next;
		first->next = second->next;
		if (second->next)
			second->next->previou = first;
		second->next = first;
		second->previou = NULL;
		first->previou = second;
		stack->b = second;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	write(1, "ss\n", 3);
}
*/

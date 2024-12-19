/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2024/12/18 21:29:36 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_node_list **stack)
{
    t_node_list	*first;
    t_node_list	*last;

    if (ft_node_list_len(*stack) > 1)
    {
        first = *stack;
        last = *stack;
        while (last->next)
            last = last->next;
        last->previou->next = NULL;
        last->previou = NULL;
        last->next = first;
        first->previou = last;
        *stack = last;
    }
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

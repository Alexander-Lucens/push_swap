/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 21:58:54 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack *stack)
{
	t_node_list	*temp;

	if (ft_node_list_len(stack->a) > 0)
	{
		temp = stack->a;
		stack->a = stack->a->next;
		if (stack->a)
			stack->a->prev = NULL;
		temp->next = NULL;
		stack->b = ft_addfront(temp, stack->b);
	}
	write(1, "pb\n", 3);
}

void	pa(t_stack *stack)
{
	t_node_list	*temp;

	if (ft_node_list_len(stack->b) > 0)
	{
		temp = stack->b;
		stack->b = stack->b->next;
		if (stack->b)
			stack->b->prev = NULL;
		temp->next = NULL;
		stack->a = ft_addfront(temp, stack->a);
	}
	write(1, "pa\n", 3);
}

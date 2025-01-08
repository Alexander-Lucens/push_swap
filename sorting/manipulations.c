/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:17:53 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 21:58:54 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_index(t_node_list *list)
{
	t_node_list	*temp;
	int			min;

	temp = list;
	min = temp->index;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

int	max_index(t_node_list *list)
{
	t_node_list	*temp;
	int			max;

	temp = list;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

void	execute_moves(t_stack *stack, t_node_list *current)
{
	while (current->moves->ra-- > 0)
		ra(stack);
	while (current->moves->rb-- > 0)
		rb(stack);
	while (current->moves->rr-- > 0)
		rr(stack);
	while (current->moves->rra-- > 0)
		rra(stack);
	while (current->moves->rrb-- > 0)
		rrb(stack);
	while (current->moves->rrr-- > 0)
		rrr(stack);
	pa(stack);
}

void	reset_moves(t_moves *moves)
{
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
}

int	required_rotations(t_node_list *list, int index)
{
	t_node_list	*temp;
	int			moves;
	int			len;

	temp = list;
	moves = 0;
	len = ft_node_list_len(list);
	while (temp && temp->index != index)
	{
		temp = temp->next;
		moves++;
	}
	if (moves > len / 2)
		moves = moves - len;
	return (moves);
}

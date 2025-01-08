/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lucens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:17:53 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 21:58:54 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_insert_position(t_node_list *a, int index)
{
	t_node_list	*current;
	int			min;
	int			max;

	current = a;
	min = min_index(a);
	max = max_index(a);
	if (index < min || index > max)
		return (min);
	while (current && current->next)
	{
		if (current->index < index && current->next->index > index)
			return (current->next->index);
		current = current->next;
	}
	return (a->index);
}

void	calculate_current_node_moves(t_stack *stack, t_node_list *current)
{
	t_moves	*moves;
	int		rotations_b;
	int		insert_position;
	int		rotations_a;

	if (!current->moves)
		current->moves = malloc(sizeof(t_moves));
	if (!current->moves)
		error();
	moves = current->moves;
	reset_moves(moves);
	rotations_b = required_rotations(stack->b, current->index);
	if (rotations_b < 0)
		moves->rrb = -rotations_b;
	else
		moves->rb = rotations_b;
	insert_position = find_insert_position(stack->a, current->index);
	rotations_a = required_rotations(stack->a, insert_position);
	if (rotations_a < 0)
		moves->rra = -rotations_a;
	else
		moves->ra = rotations_a;
}

void	unify_moves(t_node_list *current)
{
	t_moves	*moves;

	moves = current->moves;
	while (moves->ra > 0 && moves->rb > 0)
	{
		moves->rr++;
		moves->ra--;
		moves->rb--;
	}
	while (moves->rra > 0 && moves->rrb > 0)
	{
		moves->rrr++;
		moves->rra--;
		moves->rrb--;
	}
	current->total = moves->ra + moves->rb + moves->rra + \
	moves->rrb + moves->rr + moves->rrr;
}

int	get_min_moves(t_stack *stack)
{
	t_node_list	*current;
	int			min_moves;

	current = stack->b;
	min_moves = ft_node_list_len(stack->a) + ft_node_list_len(stack->b);
	while (current)
	{
		calculate_current_node_moves(stack, current);
		unify_moves(current);
		if (current->total < min_moves)
			min_moves = current->total;
		current = current->next;
	}
	return (min_moves);
}

t_node_list	*get_best_node(t_stack *stack, int min_moves)
{
	t_node_list	*current;

	current = stack->b;
	while (min_moves != current->total)
		current = current->next;
	return (current);
}

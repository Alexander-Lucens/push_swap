/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:52:39 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 22:22:30 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	optimal_move(t_stack *stack)
{
	int			min_moves;
	t_node_list	*best;

	min_moves = get_min_moves(stack);
	best = get_best_node(stack, min_moves);
	execute_moves(stack, best);
}

void	split_stack(t_stack *stack)
{
	int	min;
	int	max;
	int	mid;

	min = min_index(stack->a);
	max = max_index(stack->a);
	mid = (min + max) / 2;
	while (ft_node_list_len(stack->a) > 3)
	{
		if (stack->a->index == max || stack->a->index == mid \
		|| stack->a->index == min)
			ra(stack);
		else if (stack->a->index <= mid)
			pb(stack);
		else
		{
			pb(stack);
			rb(stack);
		}
	}
}

void	solution(t_stack *stack)
{
	if (check_order(stack->a) && !stack->b)
		return (write(1, "\n", 1), free(stack->a), free(stack->b), exit(0));
	if (ft_node_list_len(stack->a) == 2)
		sa(stack);
	else if (ft_node_list_len(stack->a) >= 3 && ft_node_list_len(stack->a) <= 6)
		dump_sort(stack);
	else if (ft_node_list_len(stack->a) > 6)
		lucens(stack);
}

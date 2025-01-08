/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 21:58:54 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack *stack)
{
	t_node_list	*a;

	a = stack->a;
	if (check_order(a))
		return ;
	if (a->number > a->next->number && a->number < a->next->next->number)
		sa(stack);
	else if (a->number > a->next->number \
	&& a->next->number > a->next->next->number)
	{
		sa(stack);
		rra(stack);
	}
	else if (a->number > a->next->number \
	&& a->next->number < a->next->next->number)
		ra(stack);
	else if (a->number < a->next->number \
	&& a->number > a->next->next->number)
		rra(stack);
	else
	{
		sa(stack);
		ra(stack);
	}
}

void	dump_sort(t_stack *stack)
{
	int	i;

	if (check_order(stack->a))
		return ;
	i = 0;
	while (ft_node_list_len(stack->a) > 3)
	{
		if (required_rotations(stack->a, i) > 0)
			while (stack->a->index != i)
				ra(stack);
		else
			while (stack->a->index != i)
				rra(stack);
		pb(stack);
		i++;
	}
	if (ft_node_list_len(stack->a) == 3)
		sort_3(stack);
	while (ft_node_list_len(stack->b) > 0)
		pa(stack);
}

void	lucens(t_stack *stack)
{
	split_stack(stack);
	sort_3(stack);
	while (stack->b)
		optimal_move(stack);
	while (check_order(stack->a) == 0)
	{
		if (required_rotations(stack->a, min_index(stack->a)) < 0)
			rra(stack);
		else if (required_rotations(stack->a, 0) > 0)
			ra(stack);
	}
}

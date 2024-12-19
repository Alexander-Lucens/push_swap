/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:52:39 by akuzmin           #+#    #+#             */
/*   Updated: 2024/12/19 19:44:02 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_order(t_node_list *list)
{
	t_node_list	*temp;

	temp = list;
	while (temp->next != NULL)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	reverse_order(t_node_list *list)
{
	t_node_list	*temp;

	temp = list;
	while (temp->next)
	{
		if (temp->number < temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int minimum(t_node_list *list)
{
	t_node_list	*temp;
	int	min;

	temp = list;
	min = temp->number;
	while (temp->next)
	{
		if (temp->number < min)
			min = temp->number;
		temp = temp->next;
	}
	return (min);
}

int maximum(t_node_list *list)
{
	t_node_list	*temp;
	int	max;

	temp = list;
	max = temp->number;
	while (temp->next)
	{
		if (temp->number > max)
			max = temp->number;
		temp = temp->next;
	}
	return (max);
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
		radix_sort(stack);
}

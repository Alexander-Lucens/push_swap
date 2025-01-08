/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:17:53 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 21:58:54 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	t_node_list	*current;
	t_node_list	*compare;
	size_t		index;

	current = stack->a;
	while (current)
	{
		index = 0;
		compare = stack->a;
		while (compare)
		{
			if (compare->number < current->number)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

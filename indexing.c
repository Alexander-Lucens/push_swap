/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:17:53 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/09 14:21:11 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*trim_newline(char *dest)
{
	int	i;

	i = 0;
	while (dest && dest[i])
	{
		if (dest[i] == '\n')
		{
			dest[i] = '\0';
			break ;
		}
		i++;
	}
	return (dest);
}

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

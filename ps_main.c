/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/08 23:16:03 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node_list	*init_node_list(char *str, size_t i)
{
	t_node_list	*node;
	long long	number;

	if (!is_number(str))
		return (NULL);
	node = malloc(sizeof(t_node_list));
	if (!node)
		return (NULL);
	number = ft_atoi(str);
	if (number > 2147483647 || number < -2147483648)
		return (NULL);
	node->number = number;
	node->index = i;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node_list	*process_args(char **args)
{
	t_node_list	*list;
	t_node_list	*node;
	size_t		i;

	i = 0;
	list = NULL;
	while (args[i])
	{
		node = init_node_list(args[i], i);
		if (!node)
			return (ft_node_clear(&list), NULL);
		ft_append(&list, node);
		i++;
	}
	return (list);
}

int	check_duplications(t_node_list *list)
{
	t_node_list	*tmp;
	t_node_list	*tmp2;

	tmp = list;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->number == tmp2->number)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

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

/**
 * IDK but mayby usefull to check also discending order
 * But its nothing about it in the subject
 */
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

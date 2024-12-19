/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:14:21 by akuzmin           #+#    #+#             */
/*   Updated: 2024/12/18 21:29:36 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_append(t_node_list **lst, t_node_list *new)
{
	t_node_list	*ex;
	t_node_list	*prev;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ex = *lst;
	prev = NULL;
	while (ex->next != NULL)
	{
		prev = ex;
		ex = ex->next;
		ex->previou = prev;
	}
	ex->next = new;
}

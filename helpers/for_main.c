/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:51:37 by akuzmin           #+#    #+#             */
/*   Updated: 2024/12/18 21:29:36 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// void	make_circular(t_node_list *list)
// {
//     t_node_list	*first;
//     t_node_list	*last;

//     if (!list)
//         return;
//     first = list;
//     last = list;
//     while (last->next)
//         last = last->next;
//     last->next = first;
//     first->previou = last;
// }

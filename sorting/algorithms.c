/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:42:23 by akuzmin           #+#    #+#             */
/*   Updated: 2024/12/19 20:32:32 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack *stack, t_node_list *current_node)
{
    t_node_list *current = current_node;

	if (check_order(current))
		return ;
    if (current->number > current->next->number && current->number < current->next->next->number)
        sa(stack);
    else if (current->number > current->next->number && current->next->number > current->next->next->number)
    {
        sa(stack);
        rra(stack);
    }
    else if (current->number > current->next->number && current->next->number < current->next->next->number)
        ra(stack);
    else if (current->number < current->next->number && current->number > current->next->next->number)
        rra(stack);
    else if (current->number < current->next->number && current->next->number > current->next->next->number)
    {
        sa(stack);
        ra(stack);
    }
}

void	sort_3_b(t_stack *stack)
{
	t_node_list *current = stack->b;
	if (reverse_order(current))
		return ;
    if (current->number < current->next->number && current->number > current->next->next->number)
        sb(stack);
    else if (current->number < current->next->number && current->next->number < current->next->next->number)
    {
        sb(stack);
        rrb(stack);
    }
    else if (current->number < current->next->number && current->next->number > current->next->next->number)
        rb(stack);
    else if (current->number > current->next->number && current->number < current->next->next->number)
        rrb(stack);
    else if (current->number > current->next->number && current->next->number < current->next->next->number)
    {
        sb(stack);
        rb(stack);
    }
}

/**
 * Return 0 if we on right position
 * Return >0 if we need to --> rotate_revers
 * Return <0 if we need to --> rotate
 */
/*
int where_to_go(t_node_list *list, int look_from, int look_before)
{
    int i;
    int j;
	t_node_list *go_up = list;
    t_node_list *go_down = list;
	
    i = 0;
	j = 0;
	if (list->number > look_from && list->number < look_before)
		return (0);
    while (go_down->number > look_from  && go_down->number < look_before && ft_node_list_len(go_down) > i++)
        rotate(&go_down);
    j += i;
	while (i--)
		reverse_rotate(&go_down);
    while (go_up->number > look_from && go_up->number < look_before && ft_node_list_len(go_up) > i++)
        reverse_rotate(&go_up);
	j -= i;
	while (i--)
		rotate(&go_up);
    return (j);
}
*/
int last_number(t_node_list *list)
{
	t_node_list *temp = list;

	while (temp->next)
		temp = temp->next;
	return (temp->number);
}

/**
 * 100 numbers --> 2500-2600 operations
 * 50 numbers --> 700-800 operations
 * 20 numbers --> 120-130 operations
 * 10 numbers --> 30-45 operations
 * 5 numbers --> 7-10 operations
 */
void	dump_sort(t_stack *stack)
{
	print_list(stack);
    while (ft_node_list_len(stack->a) > 3)
	{
		while(stack->a->number != minimum(stack->a))
			ra(stack);
		pb(stack);
	}
	if (ft_node_list_len(stack->a) == 3)
	{
		print_list(stack);
    	sort_3(stack, stack->a);
		// may be here right after segv
		// write(1, "Segfault here!!\n", 17);
		sort_3_b(stack);
	}
    while (ft_node_list_len(stack->b) > 0)
		pa(stack);
	int j = 0;
	while (!check_order(stack->a) && j++ < 10)
		rra(stack);
}
/*
void radix_sort(t_stack *stack)
{
	int i;
    t_node_list *current = stack->a;

	i = 31;
    while (check_order(stack->a) == 0)
    {
        int j = 0;
        while (j < ft_node_list_len(stack->a))
        {
            current = stack->a;
            if (((current->number >> i) & 1) == 1)
                ra(stack);
            else
                pb(stack);
            j++;
        }
        while (ft_node_list_len(stack->b) > 0)
            pa(stack);
		i--;
    }
}
*/
/// outsorce algorithm
void index_stack(t_stack *stack)
{
    t_node_list *current;
    t_node_list *compare;
    int index;

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

// static int	get_max_bits(t_node_list *stack)
// {
// 	int			max;
// 	int			max_bits;

// 	max = ft_node_list_len(stack);
// 	max_bits = maximum(stack);
// 	while ((max >> max_bits) != 0)
// 		max_bits++;
// 	return (max_bits);
// }

void radix_sort(t_stack *stack)
{
    int max_bits;
    int i;
    int j;
    int len;
    t_node_list *current;

    index_stack(stack);
    len = ft_node_list_len(stack->a);
    max_bits = 0;
    while ((len - 1) >> max_bits != 0)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < len)
        {
            current = stack->a;
            if (((current->index >> i) & 1) == 1)
                ra(stack);
            else
                pb(stack);
            j++;
        }
        while (ft_node_list_len(stack->b) > 0)
            pa(stack);
        i++;
    }
}
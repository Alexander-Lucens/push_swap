/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2024/12/19 19:31:29 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node_list
{
	int					number;
	size_t				index;
	struct s_node_list	*previou;
	struct s_node_list	*next;
}	t_node_list;

typedef struct s_stack
{
	t_node_list	*a;
	t_node_list	*b;
}	t_stack;

/// Helpers
void		ft_append(t_node_list **lst, t_node_list *new);
t_node_list	*ft_addfront(t_node_list *new, t_node_list *lst);
char		**ft_split(const char *s, char c);
long long	ft_atoi(const char *str);
void		ft_node_clear(t_node_list **lst);
int			ft_node_list_len(t_node_list *lst);

/// Checker
int			check_duplications(t_node_list *list);

/// Main
int			ft_isdigit(int c);
void		free_split(char **split);
int			is_number(char *str);
void		error(void);
t_node_list	*init_node_list(char *str, size_t i);
t_node_list	*process_args(char **args);

/// Debag and indication 
void		print_list(t_stack *stack);

/// Operators
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

/// Rotate
void		rotate(t_node_list **stack);
void		reverse_rotate(t_node_list **stack);

/// Sorting
void		solution(t_stack *stack);
int			check_order(t_node_list *list);
int			reverse_order(t_node_list *list);

/// Sorting algorithms
void		sort_3(t_stack *stack, t_node_list *current_node);
void		dump_sort(t_stack *stack);
void		radix_sort(t_stack *stack);
int			minimum(t_node_list *list);
int			maximum(t_node_list *list);
int			where_to_go(t_node_list *list, int look_from, int look_before);

#endif

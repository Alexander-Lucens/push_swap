/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:58:54 by akuzmin           #+#    #+#             */
/*   Updated: 2025/01/09 14:21:25 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./gnl/get_next_line.h"

/*======================= STRUCTURES =======================*/

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
}	t_moves;

typedef struct s_node_list
{
	long long			number;
	int					index;
	struct s_node_list	*prev;
	struct s_node_list	*next;
	t_moves				*moves;
	int					total;
}	t_node_list;

typedef struct s_stack
{
	t_node_list	*a;
	t_node_list	*b;
}	t_stack;

/*======================= PROTOTYPES =======================*/

/* for_main.c */
int			ft_isdigit(int c);
int			is_number(char *str);
void		free_split(char **split);
void		error(void);

/* ps_main.c */
t_node_list	*init_node_list(char *str, size_t i);
t_node_list	*process_args(char **args);
int			check_duplications(t_node_list *list);
int			check_order(t_node_list *list);
int			reverse_order(t_node_list *list);

/* checker */
void		execute_checker(t_stack *stack);

/* swap.c */
void		swap(t_node_list **stack);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);

/* push.c */
void		pb(t_stack *stack);
void		pa(t_stack *stack);
void		push_b(t_stack *stack);
void		push_a(t_stack *stack);

/* rotate.c */
void		rotate(t_node_list **stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);

/* rotate_reverse.c */
void		reverse_rotate(t_node_list **stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

/* manipulations.c */
int			min_index(t_node_list *list);
int			max_index(t_node_list *list);
void		execute_moves(t_stack *stack, t_node_list *current);
void		reset_moves(t_moves *moves);
int			required_rotations(t_node_list *list, int index);

/* lucens.c */
int			find_insert_position(t_node_list *a, int index);
void		calculate_current_node_moves(t_stack *stack, t_node_list *current);
void		unify_moves(t_node_list *current);
int			get_min_moves(t_stack *stack);
t_node_list	*get_best_node(t_stack *stack, int min_moves);

/* algorithms.c */
void		sort_3(t_stack *stack);
void		dump_sort(t_stack *stack);
void		lucens(t_stack *stack);

/* solution.c */
void		split_stack(t_stack *stack);
void		optimal_move(t_stack *stack);
void		solution(t_stack *stack);

/* indexing.c */
int			ft_strcmp(const char *s1, const char *s2);
char		*trim_newline(char *dest);
void		index_stack(t_stack *stack);

/* gnl */
char		*get_next_line(int fd);

/*helpers*/
void		ft_append(t_node_list **lst, t_node_list *new);
t_node_list	*ft_addfront(t_node_list *new, t_node_list *lst);
char		**ft_split(const char *s, char c);
long long	ft_atoi(const char *str);
void		ft_node_clear(t_node_list **lst);
int			ft_node_list_len(t_node_list *lst);

#endif

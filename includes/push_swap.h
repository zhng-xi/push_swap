/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzheng <xzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 09:10:40 by xzheng            #+#    #+#             */
/*   Updated: 2024/05/04 17:22:22 by xzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h> //-->delete later

typedef struct s_stack
{
	int				nb;
	int				io;
	int				cost;
	int				match;
	int				steps;
	bool			upper;
	struct s_stack	*next;
}	t_stack;

// check_input
void	free_stack(t_stack **stack);
void	error(void);
bool	check_double(t_stack **stack);
bool	check_sorted(t_stack *stack_a);

// fill_stack
t_stack	*new_stack(int nb);
void	add_to_stack(t_stack **stack, t_stack *addon);
t_stack	*split_input(char *av);
t_stack	*fill_stack(int ac, char **av);

// find
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
t_stack	*find_last(t_stack *stack);
int		find_index(t_stack *stack, int nb);

// ft_atol
long	ft_atol(char *nptr);

// ra_rb_rr
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);

// rra_rrb_rrr
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);

// sa_sb_ss_pa_pb
void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);

// size
long	stack_size(t_stack *stack);
int		get_mid(t_stack *stack);

// sort_utils
int		calc_a(t_stack **stack_a);
int		calc_b(t_stack **stack_b);
int		find_match_ab(t_stack **stack_a, t_stack **stack_b);
int		find_match_ba(t_stack **stack_a, t_stack **stack_b);

// sort_utils2
int		get_steps_ab(t_stack **stack_a, t_stack **stack_b);
int		get_steps_ba(t_stack **stack_a, t_stack **stack_b);
int		perfect_match(t_stack *stack_a);

// sort_utils3
void	a_rarb(t_stack **stack_a, t_stack **stack_b, int a, int b);
void	a_rrarrb(t_stack **stack_a, t_stack **stack_b, int a, int b);
void	do_steps_ab(t_stack **stack_a, t_stack **stack_b);

// sort_utils4
void	b_rarb(t_stack **stack_a, t_stack **stack_b, int a, int b);
void	b_rrarrb(t_stack **stack_a, t_stack **stack_b, int a, int b);
void	do_steps_ba(t_stack **stack_a, t_stack **stack_b);

// start_sort
void	sort_three(t_stack **stack_a);
void	start_b(t_stack **stack_a, t_stack **stack_b);
t_stack	**push_to_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*push_to_b(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a);

///////////////////////////////////////////////////////
void	print_stack(t_stack **stack);

#endif
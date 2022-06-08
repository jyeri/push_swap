/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:27:41 by jrummuka          #+#    #+#             */
/*   Updated: 2022/06/08 20:01:02 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_stacks
{
	int	stack[10000];
	int	stacksize;
	int	actualsize;
	int	ainst;
	int	visual;
	int	t;

}	t_stacks;

int		sa(t_stacks *stack1, t_stacks *stack2);
int		sb(t_stacks *stack1, t_stacks *stack2);
int		ss(t_stacks *stack1, t_stacks *stack2);
int		pa(t_stacks *stack1, t_stacks *stack2);
int		pb(t_stacks *stack1, t_stacks *stack2);
int		ra(t_stacks *stack1, t_stacks *stack2);
int		rb(t_stacks *stack1, t_stacks *stack2);
int		rr(t_stacks *stack1, t_stacks *stack2);
int		rra(t_stacks *stack1, t_stacks *stack2);
int		rrb(t_stacks *stack1, t_stacks *stack2);
int		rrr(t_stacks *stack1, t_stacks *stack2);
int		do_sa(t_stacks *stack1, t_stacks *stack2);
int		do_sb(t_stacks *stack1, t_stacks *stack2);
int		do_ss(t_stacks *stack1, t_stacks *stack2);
int		do_pa(t_stacks *stack1, t_stacks *stack2);
int		do_pb(t_stacks *stack1, t_stacks *stack2);
int		do_ra(t_stacks *stack1, t_stacks *stack2);
int		do_rb(t_stacks *stack1, t_stacks *stack2);
int		do_rr(t_stacks *stack1, t_stacks *stack2);
int		do_rra(t_stacks *stack1, t_stacks *stack2);
int		do_rrb(t_stacks *stack1, t_stacks *stack2);
int		do_rrr(t_stacks *stack1, t_stacks *stack2);
void	swap(t_stacks *stack);
void	rotate(t_stacks *stack);
void	reverse_rotate(t_stacks *stack);
//checker.c
void	init_stack(int argc, char **argv, t_stacks *stack1, t_stacks *stack2);
void	print_stacks(t_stacks *stack1, t_stacks *stack2);
void	solve(t_stacks *stack1, t_stacks *stack2, char *ins);
int		ft_atoi_w_intlimit(const char *str);
int		is_sorted(t_stacks *stack);
int		doublecheck(t_stacks *stack, int i);
int		ft_digitss(char *str);
int		ft_parse_multi_input(int argc, char **argv, int j, t_stacks *stack1);
//push_swap.c
int		calc_chunk(t_stacks *stack1);
int		solver(t_stacks *stack1, t_stacks *stack2);
int		sort_b(t_stacks *stack1, t_stacks *stack2);
int		sort_big_b(t_stacks *stack1, t_stacks *stack2);
int		solversmall(t_stacks *stack1, t_stacks *stack2);
int		sortsmallish(t_stacks *stack1, t_stacks *stack2, int low, int high);
int		solver500plus(t_stacks *stack1, t_stacks *stack2, int i, int j);
//int		solver500plus(t_stacks *stack1, t_stacks *stack2);
//swap_funcs.c
int		get_top(t_stacks *stack, int qmed);
int		get_bottom(t_stacks *stack1, int qmed);
int		get_b_top(t_stacks *stack, int key);
int		get_b_bottom(t_stacks *stack1, int key);
int		get_low(t_stacks *stack);
int		get_high(t_stacks *stack);
//helpers.c
void	ft_errorext(void);
int		is_sorted(t_stacks *stack);
int		int_len(int nm);
int		ft_digitss(char *str);
//bonus.c
void	init_bonus(t_stacks *stack1,t_stacks *stack2);
void	ft_bonus(t_stacks *stack1, t_stacks *stack2, char *str);
void	printbonus(t_stacks *stack1, t_stacks *stack2);

#endif
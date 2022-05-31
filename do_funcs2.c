/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:29:13 by jrummuka          #+#    #+#             */
/*   Updated: 2022/05/31 19:30:25 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_ss(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("ss\n");
	ss(stack1, stack2);
	return (0);
}

//Take top of b -> top of A
//nothing if B is empty
int	do_pa(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("pa\n");
	pa(stack1, stack2);
	return (0);
}

//Take top of A -> top of B
//nothing if A is empty
int	do_pb(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("pb\n");
	pb(stack1, stack2);
	return (0);
}

//move every element is stack A up by one, First element -> Last element
int	do_ra(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("ra\n");
	ra(stack1, stack2);
	return (0);
}

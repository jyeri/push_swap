/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_funcs1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:29:01 by jrummuka          #+#    #+#             */
/*   Updated: 2022/05/31 19:30:55 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//move every element is stack B up by one, First element -> Last element
int	do_rb(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("rb\n");
	rb(stack1, stack2);
	return (0);
}

int	do_rr(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("rr\n");
	rr(stack1, stack2);
	return (0);
}

//move every element is stack A down by one, LAST element -> FIRST element
int	do_rra(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("rra\n");
	rra(stack1, stack2);
	return (0);
}

//move every element is stack B down by one, LAST element -> FIRST element
int	do_rrb(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("rrb\n");
	rrb(stack1, stack2);
	return (0);
}

int	do_rrr(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("rrr\n");
	rrr(stack1, stack2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:20:17 by jrummuka          #+#    #+#             */
/*   Updated: 2022/06/08 20:03:41 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rb(t_stacks *stack1, t_stacks *stack2)
{
	stack1->ainst++;
	rotate(stack2);
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

int	rr(t_stacks *stack1, t_stacks *stack2)
{
	stack1->ainst++;
	rotate(stack1);
	rotate(stack2);
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

int	rra(t_stacks *stack1, t_stacks *stack2)
{
	stack1->ainst++;
	reverse_rotate(stack1);
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

int	rrb(t_stacks *stack1, t_stacks *stack2)
{
	stack1->ainst++;
	reverse_rotate(stack2);
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

int	rrr(t_stacks *stack1, t_stacks *stack2)
{
	stack1->ainst++;
	reverse_rotate(stack1);
	reverse_rotate(stack2);
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

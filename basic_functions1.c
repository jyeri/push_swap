/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:20:37 by jrummuka          #+#    #+#             */
/*   Updated: 2022/06/08 20:03:47 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sb(t_stacks *stack1, t_stacks *stack2)
{
	swap(stack2);
	stack1->ainst++;
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

int	ss(t_stacks *stack1, t_stacks *stack2)
{
	stack1->ainst++;
	swap(stack1);
	swap(stack2);
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

int	pa(t_stacks *stack1, t_stacks *stack2)
{
	int			tmp;
	int			j;

	stack1->ainst++;
	j = stack1->actualsize;
	if (stack2->actualsize > 0)
	{
		tmp = stack2->stack[0];
		while (j > 0)
		{
			stack1->stack[j] = stack1->stack[j - 1];
			j--;
		}
		stack1->stack[0] = tmp;
		j = -1;
		while (j++ < stack2->actualsize - 1)
			stack2->stack[j] = stack2->stack[j + 1];
		stack1->actualsize++;
		stack2->actualsize--;
	}
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

int	pb(t_stacks *stack1, t_stacks *stack2)
{
	int			tmp;
	int			j;

	stack1->ainst++;
	j = stack2->actualsize;
	if (stack1->actualsize > 0)
	{
		tmp = stack1->stack[0];
		while (j > 0)
		{
			stack2->stack[j] = stack2->stack[j - 1];
			j--;
		}
		stack2->stack[0] = tmp;
		j = -1;
		while (j++ < stack1->actualsize)
			stack1->stack[j] = stack1->stack[j + 1];
		stack2->actualsize++;
		stack1->actualsize--;
	}
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

int	ra(t_stacks *stack1, t_stacks *stack2)
{
	stack1->ainst++;
	rotate(stack1);
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

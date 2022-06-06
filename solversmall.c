/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solversmall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:32:26 by jrummuka          #+#    #+#             */
/*   Updated: 2022/06/06 16:31:24 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sortsmallish(t_stacks *stack1, t_stacks *stack2, int low, int high)
{
	while (stack1->actualsize > 3)
	{
		if (stack1->stack[0] == high || stack1->stack[0] == low)
			do_pb(stack1, stack2);
		else
			do_ra(stack1, stack2);
	}
	solversmall(stack1, stack2);
	while (is_sorted(stack1) != 0 || stack2->actualsize > 0)
	{
		if (stack2->stack[0] == high)
		{
			do_pa(stack1, stack2);
			do_ra(stack1, stack2);
		}
		else
			do_pa(stack1, stack2);
	}
	return (0);
}

int	solvertiny(t_stacks *stack1, t_stacks *stack2, int low, int high)
{
	while (is_sorted(stack1))
	{
		if (stack1->stack[stack1->actualsize - 1] == high)
			do_sa(stack1, stack2);
		else if (stack1->stack[0] == high)
		{
			if (stack1->stack[stack1->actualsize - 1] == low)
			{
				do_sa(stack1, stack2);
				do_rra(stack1, stack2);
			}
			else
				do_ra(stack1, stack2);
		}
		else if (stack1->stack[0] == low)
		{
			do_sa(stack1, stack2);
			do_ra(stack1, stack2);
		}
		else
			do_rra(stack1, stack2);
	}
	return (0);
}

int	solversmall(t_stacks *stack1, t_stacks *stack2)
{
	int	low;
	int	high;

	low = get_low(stack1);
	high = get_high(stack1);
	if (stack1->actualsize == 2 && is_sorted(stack1) != 0)
		do_sa(stack1, stack2);
	else if (stack1->actualsize < 4)
		solvertiny(stack1, stack2, low, high);
	else
		sortsmallish(stack1, stack2, low, high);
	return (0);
}

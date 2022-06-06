/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverbig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:33:19 by jrummuka          #+#    #+#             */
/*   Updated: 2022/06/06 15:18:51 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	from_top(t_stacks *stack1, t_stacks *stack2, int top)
{
	int	low;

	low = get_low(stack2);
	while (top > 0)
	{
		if (top == 1 && stack2->actualsize > 1
			&& stack2->stack[0] < stack2->stack[1] && stack1->actualsize > 1)
			do_ss(stack1, stack2);
		else
		{
			if (stack2->stack[0] == low && stack2->actualsize > 1
				&& stack1->actualsize > 1)
				do_rr(stack1, stack2);
			else
				do_ra(stack1, stack2);
		}
		top--;
	}
}

void	from_bottom(t_stacks *stack1, t_stacks *stack2, int top, int bottom)
{
	int	low;

	low = get_low(stack2);
	while (bottom > 0)
	{
		if (top == 1 && stack2->actualsize > 1
			&& stack2->stack[0] < stack2->stack[1] && stack1->actualsize > 1)
			do_ss(stack1, stack2);
		else
		{
			if (stack2->stack[0] == low
				&& stack2->actualsize > 1 && stack1->actualsize > 1)
				do_rrr(stack1, stack2);
			else
				do_rra(stack1, stack2);
		}
		bottom--;
	}
}

int	get_big_median(t_stacks *stack, int size)
{
	int	tmp[10000];
	int	i;
	int	j;
	int	med;

	i = 0;
	med = 0;
	ft_bzero(tmp, stack->actualsize);
	while (i < stack->actualsize)
	{
		j = i - 1;
		while (j >= 0 && tmp[j] > stack->stack[i])
		{
			tmp[j + 1] = tmp[j];
			j--;
		}
		tmp[j + 1] = stack->stack[i];
		i++;
	}
	tmp[stack->actualsize] = '\0';
	if (stack->actualsize < size + 1)
		med = get_high(stack);
	else
		med = tmp[size];
	return (med);
}

int	solver500plus(t_stacks *stack1, t_stacks *stack2, int chunksize, int pushed)
{
	int	top;
	int	bottom;
	int	qmed;

	while (stack1->actualsize > 1)
	{
		qmed = get_big_median(stack1, chunksize);
		pushed = 0;
		while (pushed < chunksize && stack1->actualsize >= 1)
		{
			top = get_top(stack1, qmed);
			bottom = get_bottom(stack1, qmed);
			if (top < bottom)
				from_top(stack1, stack2, top);
			else
				from_bottom(stack1, stack2, top, bottom);
			if (stack1->stack[0] <= qmed || stack1->actualsize < 2)
			{
				do_pb(stack1, stack2);
				pushed++;
			}
		}
	}
	sort_big_b(stack1, stack2);
	return (0);
}

int	sort_big_b(t_stacks *stack1, t_stacks *stack2)
{
	int	high;
	int	top;
	int	bottom;

	while (stack2->actualsize > 0)
	{
		high = get_high(stack2);
		top = get_b_top(stack2, high);
		bottom = get_b_bottom(stack2, high);
		if (top <= bottom)
		{
			while (top-- > 0)
				do_rb(stack1, stack2);
		}
		else
		{
			while (bottom-- > 0)
				do_rrb(stack1, stack2);
		}
		do_pa(stack1, stack2);
	}
	return (0);
}

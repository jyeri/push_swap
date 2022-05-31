/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:52:52 by jrummuka          #+#    #+#             */
/*   Updated: 2022/05/31 19:39:39 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	get_high(t_stacks *stack)
{
	int	i;
	int	hold;

	i = 0;
	hold = stack->stack[i];
	while (i <= stack->actualsize)
	{
		if (hold < stack->stack[i])
			hold = stack->stack[i];
		i++;
	}
	return (hold);
}

//int	is_dec_sorted(t_stacks *stack)
//{
//	int	i;
//
//	i = stack->actualsize - 1;
//	while (0 < i)
//	{
//		if (stack->stack[i] > stack->stack[i - 1])
//			return (1);
//		i--;
//	}
//	return (0);
//}

int	get_low(t_stacks *stack)
{
	int	low;
	int	i;

	i = 0;
	low = stack->stack[i];
	while (i < stack->actualsize)
	{
		if (stack->stack[i] < low)
			low = stack->stack[i];
		i++;
	}
	return (low);
}

//int	get_median(t_stacks *stack, int size)
//{
//	int	tmp[1000];
//	int	i = 0;
//	int	j;
//	int	med;
//
//	ft_bzero(tmp, size);
//	while (i < size)
//	{
//		j = i - 1;
//		while (j >= 0 && tmp[j] > stack->stack[i])
//		{
//			tmp[j + 1] = tmp[j];
//			j--;
//		}
//		tmp[j + 1] = stack->stack[i];
//		i++;
//	}
//	tmp[size] = '\0';
//	med = tmp[size / 2];
//	return(med);
//}

//int	solver(t_stacks *stack1, t_stacks *stack2)
//{
//	int	median;
//	int	pushed;
//
//	pushed = 0;
//	median = get_median(stack1, stack1->actualsize);
//	while (stack1->actualsize > 1)
//	{
//		while (pushed < (stack1->actualsize / 2))
//		{
//			if (stack1->stack[0] < median)
//			{
//				pb(stack1, stack2);
//				pushed++;
//			}
//			else if (stack1->stack[stack1->actualsize] > median)
//			{
//				rra(stack1, stack2);
//				pb(stack1, stack2);
//				pushed++;
//			}
//			else if (stack1->stack[0] >= median)
//			{
//				ra (stack1, stack2);
//			}
//		}
//		median = get_median(stack1, stack1->actualsize);
//		pushed = 0;
//	}
//	sort_b(stack1, stack2);
//	while (stack2->actualsize > 0)
//	{
//		pa(stack1, stack2);
//	}
//	return (0);
//}

int	get_top(t_stacks *stack, int qmed)
{
	int i;

	i = 0;
	while (i <= stack->actualsize && stack->stack[i] >= qmed)
		i++;
	return (i);
}

int	get_bottom(t_stacks *stack1, int qmed)
{
	int	i;
	int	j;

	j = stack1->actualsize - 1;
	i = 1;
	while (j > 0 && stack1->stack[j] >= qmed)
	{
		j--;
		i++;
	}
	return (i);
}

int	get_b_top(t_stacks *stack, int key)
{
	int	i;

	i = 0;
	while (stack->stack[i] != key)
		i++;
	return (i);
}

int	get_b_bottom(t_stacks *stack1, int key)
{
	int	i;
	int	j;

	j = stack1->actualsize - 1;
	i = 1;
	while (stack1->stack[j] != key)
	{
		i++;
		j--;
	}
	return (i);
}

//int	sort_b(t_stacks *stack1, t_stacks *stack2)
//{
//	int	high;
//	high = get_high(stack2);
//	while (stack2->actualsize > 0)
//	{
//		while (stack2->stack[0] != high)
//		{
//			do_rb(stack1, stack2);;
//		}
//		do_pa(stack1, stack2);
//		high = get_high(stack2);
//	}
//	return (0);
//}

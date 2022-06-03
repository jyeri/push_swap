/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:52:52 by jrummuka          #+#    #+#             */
/*   Updated: 2022/06/03 13:56:20 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_high(t_stacks *stack)
{
	int	i;
	int	hold;

	i = 0;
	hold = stack->stack[i];
	while (i < stack->actualsize)
	{
		if (hold < stack->stack[i])
			hold = stack->stack[i];
		i++;
	}
	return (hold);
}

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

int	get_top(t_stacks *stack, int qmed)
{
	int	i;

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

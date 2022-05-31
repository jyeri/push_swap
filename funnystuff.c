/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funnystuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:52:33 by jrummuka          #+#    #+#             */
/*   Updated: 2022/05/31 20:01:04 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "stdio.h"

void	swap(t_stacks *stack)
{
	int	tmp;

	if (stack->actualsize > 1)
	{
		tmp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = tmp;
	}
}

void	rotate(t_stacks *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->stack[0];
	while (i < stack->actualsize - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[stack->actualsize - 1] = tmp;
}

void	reverse_rotate(t_stacks *stack)
{
	int	tmp;
	int	i;

	i = stack->actualsize - 1;
	tmp = stack->stack[stack->actualsize - 1];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = tmp;
}

int	sa(t_stacks *stack1, t_stacks *stack2)
{
	swap(stack1);
	stack1->ainst++;
	if (stack1->visual || stack2->visual)
		print_stacks(stack1, stack2);
	return (0);
}

void	print_stacks(t_stacks *stack1, t_stacks *stack2)
{
	int	i;
	int	len;

	len = 1;
	i = 0;
	ft_putstr("\n-------------------\n");
	while (i < stack1->actualsize || i < stack2->actualsize)
	{
		len = int_len(stack1->stack[i]);
		if (i < stack1->actualsize)
			ft_putnbr(stack1->stack[i]);
		while (10 - len++ > 0)
			ft_putchar(' ');
		ft_putstr("|  ");
		if (i < stack2->actualsize)
			ft_putnbr(stack2->stack[i]);
		else
			ft_putstr("  ");
		ft_putchar('\n');
		i++;
	}
	ft_putstr("-------------------\nstack A   | stack B\n-------------------\n\n");
}

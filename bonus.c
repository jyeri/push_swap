/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:48:40 by jrummuka          #+#    #+#             */
/*   Updated: 2022/06/08 20:05:41 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_bonus(t_stacks *stack1,t_stacks *stack2)
{
	stack1->visual = 0;
	stack2->visual = 0;
	stack1->t = 0;
	stack2->t = 0;

}

void	ft_bonus(t_stacks *stack1, t_stacks *stack2, char *str)
{
	if (!ft_strcmp(str, "-v"))
	{
		stack1->visual = 1;
		stack2->visual = 1;
	}
	else if (!ft_strcmp(str, "-t"))
	{
		stack1->t = 1;
		stack2->t = 1;
	}
}

void	printbonus(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("Total instructions used is: ");
	ft_putnbr(stack1->ainst + stack2->ainst);
	ft_putchar('\n');
}

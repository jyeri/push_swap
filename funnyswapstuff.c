/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funnyswapstuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:52:38 by jrummuka          #+#    #+#             */
/*   Updated: 2022/05/31 19:30:45 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//swap 2first elements of stack a
//do nothing if array size of 1 or less
int	do_sa(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("sa\n");
	sa(stack1, stack2);
	return (0);
}

//swap 2first elements of stack a
//do nothing if array size of 1 or less
int	do_sb(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("sb\n");
	sb(stack1, stack2);
	return (0);
}

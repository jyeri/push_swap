/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:25:09 by jrummuka          #+#    #+#             */
/*   Updated: 2022/05/31 19:25:18 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_errorext(void)
{
	ft_putstr("Error\n");
	exit(-1);
}

int	is_sorted(t_stacks *stack)
{
	int	i;

	i = 0;
	while (stack->actualsize - 1 > i)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:52:46 by jrummuka          #+#    #+#             */
/*   Updated: 2022/05/31 19:04:08 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stacks	stack1;
	t_stacks	stack2;
	int			total;

	if (argc > 1)
	{
		init_stack(argc, argv, &stack1, &stack2);
		if (is_sorted(&stack1) != 0)
		{
			if (stack1.actualsize < 6)
				solversmall(&stack1, &stack2);
			else
				solver500plus(&stack1, &stack2);
		}
		total = stack1.ainst + stack2.ainst;
	}
	return (0);
}

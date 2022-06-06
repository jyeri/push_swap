/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:52:46 by jrummuka          #+#    #+#             */
/*   Updated: 2022/06/06 15:18:37 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	calc_chunk(t_stacks *stack1)
{
	int	i;

	if (stack1->actualsize > 499)
		i = stack1->actualsize / 11;
	else if (stack1->actualsize > 99)
		i = stack1->actualsize / 5;
	else
		i = stack1->actualsize / 2;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stacks	stack1;
	t_stacks	stack2;
	int			chunksize;

	if (argc > 1)
	{
		init_stack(argc, argv, &stack1, &stack2);
		if (is_sorted(&stack1) != 0)
		{
			if (stack1.actualsize < 6)
				solversmall(&stack1, &stack2);
			else
			{
				chunksize = calc_chunk(&stack1);
				solver500plus(&stack1, &stack2, chunksize, 0);
			}
		}
	}
	return (0);
}

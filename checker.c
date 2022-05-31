/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:52:26 by jrummuka          #+#    #+#             */
/*   Updated: 2022/05/31 18:52:27 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stacks	stack1;
	t_stacks	stack2;
	char		*line;

	if (argc > 1)
		init_stack(argc, argv, &stack1, &stack2);
	while (get_next_line(0, &line) > 0)
		solve(&stack1, &stack2, line);
	if (!(is_sorted(&stack1)) && stack2.actualsize == 0)
		printf("OK\n");
	else
		printf("KO\n");
}

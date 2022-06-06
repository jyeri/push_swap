/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <jrummuka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:52:21 by jrummuka          #+#    #+#             */
/*   Updated: 2022/06/06 16:54:24 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_parse_multi_input(int argc, char **argv, int j, t_stacks *stack1)
{
	int	nm;
	int	i;

	nm = 0;
	i = 0;
	while (j < argc)
	{
		if (ft_digitss(argv[j]))
			ft_errorext();
		nm = (int)ft_atoi_w_intlimit(argv[j]);
		stack1->stack[i] = nm;
		i++;
		j++;
	}
	return (i);
}

int	ft_parse_input(char *str, t_stacks *stack1, int i, int j)
{
	char	*tmp;
	int		k;

	k = 0;
	tmp = (char *)malloc(sizeof(char) * 10 + 1);
	while (str[i] != '\0')
	{
		while (str[i] != ' ' && str[i] != '\0')
			tmp[j++] = str[i++];
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		if (!ft_digitss(tmp))
			stack1->stack[k++] = (int)ft_atoi(tmp);
		else
		{
			free(tmp);
			ft_errorext();
		}
		ft_bzero(tmp, j);
		j = 0;
	}
	stack1->stack[k] = '\0';
	free(tmp);
	return (k);
}

void	solve(t_stacks *stack1, t_stacks *stack2, char *ins)
{
	if (ft_strcmp("sa", ins) == 0)
		sa(stack1, stack2);
	else if (ft_strcmp("sb", ins) == 0)
		sb(stack1, stack2);
	else if (ft_strcmp("ss", ins) == 0)
		ss(stack1, stack2);
	else if (ft_strcmp("pa", ins) == 0)
		pa(stack1, stack2);
	else if (ft_strcmp("pb", ins) == 0)
		pb(stack1, stack2);
	else if (ft_strcmp("ra", ins) == 0)
		ra(stack1, stack2);
	else if (ft_strcmp("rb", ins) == 0)
		rb(stack1, stack2);
	else if (ft_strcmp("rr", ins) == 0)
		rr(stack1, stack2);
	else if (ft_strcmp("rra", ins) == 0)
		rra(stack1, stack2);
	else if (ft_strcmp("rrb", ins) == 0)
		rrb(stack1, stack2);
	else if (ft_strcmp("rrr", ins) == 0)
		rrr(stack1, stack2);
	else
		ft_errorext();
}

void	init_struct(t_stacks *stack1, t_stacks *stack2, int i)
{
	stack2->stacksize = i;
	stack2->actualsize = 0;
	stack1->ainst = 0;
	stack2->ainst = 0;
}

void	init_stack(int argc, char **argv, t_stacks *stack1, t_stacks *stack2)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	ft_bzero(stack1->stack, 10000);
	ft_bzero(stack2->stack, 10000);
	stack1->visual = 0;
	stack2->visual = 0;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		stack1->visual = 1;
		stack2->visual = 1;
		j++;
	}
	if (argc > 2)
		i = ft_parse_multi_input(argc, argv, j, stack1);
	else if (argc == 2)
		i = ft_parse_input(argv[j], stack1, 0, 0);
	stack1->actualsize = i;
	if (stack1->actualsize > 1 && doublecheck(stack1, 0) != 0)
		ft_errorext();
	init_struct(stack1, stack2, i);
}

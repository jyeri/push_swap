#include "checker.h"
#include <stdio.h>

void	ft_errorext()
{
	ft_putstr("Error\n");
	exit(-1);
}

int		is_sorted(t_stacks *stack)
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

int		doublecheck(t_stacks *stack)
{
	int tmp[1000];
	int i;
	int j;

	i = 0;
	ft_bzero(tmp, stack->actualsize);
	while (i < stack->actualsize)
	{
		j = i - 1;
		while (j >= 0 && tmp[j] > stack->stack[i])
		{
			tmp[j + 1] = tmp[j];
			j--;
		}
		tmp[j + 1] = stack->stack[i];
		i++;
	}
	tmp[stack->actualsize] = '\0';
	i = 0;
	while (i < stack->actualsize)
	{
		if (tmp[i] == tmp[i + 1])
			return (1);
		i++; 
	}
	return 0;
}

int	ft_parse_input(char *str, t_stacks *stack1)
{
	char	*tmp;
	int		nm;
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	tmp = (char *)malloc(sizeof(char) * 10 + 1);
	while (str[i] != '\0')
	{
		while(str[i] != ' ' && str[i] != '\0')
			tmp[j++] = str[i++];
		while(str[i] == ' ' && str[i] != '\0')
			i++;
		if(!ft_digitss(tmp))
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

void	print_stacks(t_stacks *stack1, t_stacks *stack2)
{
	int	i;

	i = 0;
	printf("\n-------------------------------------------\n");
	while (i < stack1->actualsize)
	{
		printf("stack A[%d]: %d\n", i, stack1->stack[i]);
		i++;
	}
	i = 0;
	printf("\n-------------------------------------------\n");
	while (i < stack2->actualsize)
	{
		printf("stack B[%d]: %d\n", i, stack2->stack[i]);
		i++;
	}
}

void	solve(t_stacks *stack1, t_stacks *stack2, char *ins)
{
	if (ft_strcmp("sa", ins) == 0)
		sa(stack1);
	else if (ft_strcmp("sb", ins) == 0)
		sb(stack2);
	else if (ft_strcmp("ss", ins) == 0)
		ss(stack1, stack2);
	else if (ft_strcmp("pa", ins) == 0)
		pa(stack1, stack2);
	else if (ft_strcmp("pb", ins) == 0)
		pb(stack1, stack2);
	else if (ft_strcmp("ra", ins) == 0)
		ra(stack1);
	else if (ft_strcmp("rb", ins) == 0)
		rb(stack2);
	else if (ft_strcmp("rr", ins) == 0)
		rr(stack1, stack2);
	else if (ft_strcmp("rra", ins) == 0)
		rra(stack1);
	else if (ft_strcmp("rrb", ins) == 0)
		rrb(stack2);
	else if (ft_strcmp("rrr", ins) == 0)
		rrr(stack1, stack2);
	else
	{
		printf("inst: |%s|\nline: |%s|\n", "sa", ins);
		printf("invalid instruction: %s!\n", ins);
	}
}


int	ft_digitss(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (1);
	}
	return (0);
}


void	init_stack(int argc, char **argv, t_stacks *stack1, t_stacks *stack2)
{
	int	i;
	int	nm;

	nm = 0;
	i = 0;
	ft_bzero(stack1->stack, 10000);
	ft_bzero(stack2->stack, 10000);
	if (argc > 2)
	{
		while (i < argc - 1)
		{
			if (ft_digitss(argv[i + 1]))
				ft_errorext();
			nm = (int)ft_atoi(argv[i + 1]);
			stack1->stack[i] = nm;
			i++;
		}
	}
	else if (argc == 2)
		i = ft_parse_input(argv[1], stack1);
	stack1->actualsize = i;
	if (doublecheck(stack1) != 0)
		ft_errorext();
	stack2->stacksize = i;
	stack2->actualsize = 0;
	stack1->ainst = 0;
	stack1->ainst = 0;
}
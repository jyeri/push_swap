#include "checker.h"
#include <stdio.h>

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

void	print_stacks(t_stacks *stack1, t_stacks *stack2)
{
	int	i;

	i = 0;
	printf("s1 act: %d s2 act: %d\n", stack1->actualsize, stack2->actualsize);
	while (i < stack1->actualsize)
	{
		printf("stack A[%d]: %d\n", i, stack1->stack[i]);
		i++;
	}
	i = 0;
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

void	init_stack(int argc, char **argv, t_stacks *stack1, t_stacks *stack2)
{
	int	i;
	int	nm;

	nm = 0;
	i = 0;

	while (i < argc - 1)
	{
		nm = (int)atoi(argv[i + 1]);
		stack1->stack[i] = nm;
		i++;
		//check doubles on stack1
//		if (doublecheck(stack1, i))
//			printf("error in doubles");
	}
	stack1->stacksize = i;
	stack1->actualsize = i;
	stack2->stacksize = i;
	stack2->actualsize = 0;
	stack1->ainst = 0;
	stack1->ainst = 0;
}

//int	doublecheck (t_stacks *stack1, int i)
//{
//	int	j;
//
//	j = 0;
//	while (i > j)
//	{
//		//check the doubles
//		if (blaablaablaa)
//			return (1);
//	}
//	return (0);
//}


//int	main(int argc, char **argv)
//{
//	t_stacks	stack1;
//	t_stacks	stack2;
//	char		*line;
//
//	if (argc > 1)
//		init_stack(argc, argv, &stack1, &stack2);
//	while (get_next_line(0, &line) > 0)
//		solve(&stack1, &stack2, line);
//	//sorter function??
//	if (!(is_sorted(&stack1)) && stack2.actualsize == 0)
//	{
//		printf("VITUNJEES!\n");
//		print_stacks(&stack1, &stack2);
//	}
//	else
//	{
//		printf("VOI EI, STACKIT ON NAIN:\n");
//		print_stacks(&stack1, &stack2);
//	}
//	//printer function??
//	//error exit function
//}

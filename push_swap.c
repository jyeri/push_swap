#include "checker.h"
#include <stdio.h>

int	get_high(t_stacks *stack)
{
	int i;
	int hold;

	i = 0;
	while (i < stack->actualsize)
	{
		if (hold < stack->stack[i])
			hold = stack->stack[i];
		i++;
	}
	return (hold);
	
}

int	is_dec_sorted(t_stacks *stack)
{
	int	i;

	i = stack->actualsize - 1;
	while (0 < i)
	{
		if (stack->stack[i] > stack->stack[i - 1])
			return (1);
		i--;
	}
	return (0);
}

int	get_median(t_stacks *stack, int size)
{
	int tmp[1000];
	int i = 0;
	int j;
	int med;

	ft_bzero(tmp, size);
	while (i < size)
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
	tmp[size] = '\0';
	med = tmp[size / 2];
	sleep(1);
	return(med);
}

int	solver(t_stacks *stack1, t_stacks *stack2)
{
	int median;
	int pushed;

	pushed = 0;
	median = get_median(stack1, stack1->actualsize);
	while (stack1->actualsize > 1)
	{
		while (pushed < (stack1->actualsize / 2))
		{
			if (stack1->stack[0] < median)
			{
				pb(stack1, stack2);
				pushed++;
			}
			else if (stack1->stack[stack1->actualsize] > median)
			{
				rra(stack1);
				pb(stack1, stack2);
				pushed++;
			}
			else if (stack1->stack[0] >= median)
			{
				ra (stack1);
			}
		}
		median = get_median(stack1, stack1->actualsize);
		pushed = 0;
		print_stacks(stack1, stack2);
//		if (stack2->actualsize > 2)
//			sort_b(stack1, stack2);
	}
	sort_b(stack1, stack2);
	while (stack2->actualsize > 0)
	{
		pa(stack1, stack2);
		print_stacks(stack1, stack2);
	}

	return (0);
}

int	sort_b(t_stacks *stack1, t_stacks *stack2)
{
	printf("B SORT\n");
	int high;
	high = get_high(stack2);
	while (stack2->actualsize > 0)
	{
		while (stack2->stack[0] != high)
		{
			rb(stack2);
		}
		pa(stack1, stack2);
		high = get_high(stack2);
		print_stacks(stack1, stack2);
	}
//	while (is_dec_sorted(stack2))
//	{
//		if (stack2->stack[0] < stack2->stack[1])
//			rb(stack2);
//		else
//			sb(stack2);
//		print_stacks(stack1, stack2);
//	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stack1;
	t_stacks	stack2;

	if (argc > 1)
		init_stack(argc, argv, &stack1, &stack2);
//	while (get_next_line(0, &line) > 0)
	solver(&stack1, &stack2);
	//sorter function??
//	if (!(is_sorted(&stack1)) && stack2.actualsize == 0)
//		printf("VITUNJEES!\n");
//	else
//	{
//		printf("VOI EI, STACKIT ON NAIN:\n");
//		print_stacks(&stack1, &stack2);
//	}
	print_stacks(&stack1, &stack2);
	//printer function??
	//error exit function
	return 0;
}

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

int get_low(t_stacks *stack)
{
	int low;
	int i;

	i = 0;
	low = stack->stack[i];
	while (stack->stack[i])
	{
		if (stack->stack[i] < low)
			low = stack->stack[i];
		i++;
	}
	return (low);
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
	}
	sort_b(stack1, stack2);
	while (stack2->actualsize > 0)
	{
		pa(stack1, stack2);
	}

	return (0);
}

int get_top(t_stacks *stack, int qmed)
{
	int i;

	i = 0;
	while (stack->stack[i] >= qmed)
		i++;
	return (i);
}

int get_bottom(t_stacks *stack1, int qmed)
{
	int i;
	int j;

	j = stack1->actualsize - 1;
	i = 1;
	while (stack1->stack[j] >= qmed)
	{
		j--;
		i++;
	}
	return (i);
}

int get_b_top(t_stacks *stack, int key)
{
	int i;

	i = 0;
	while (stack->stack[i] != key)
		i++;
	return (i);
}

int get_b_bottom(t_stacks *stack1, int key)
{
	int i;
	int j;

	j = stack1->actualsize - 1;
	i = 1;
	while (stack1->stack[j] != key)
	{
		j--;
		i++;
	}
	return (i);
}

int	get_big_median(t_stacks *stack, int size)
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
	if (size < 20)
	{
		med = tmp[size - 1];
	}
	else
		med = tmp[20];
	return(med);
}

int	solver500plus(t_stacks *stack1, t_stacks *stack2)
{
	int qmed;
	int pushed;
	int top;
	int bottom;
	int low;
	int i;
	int j;

	i = 0;
	j = 0;
	pushed = 0;
	qmed = get_big_median(stack1, stack1->actualsize);
	top = get_top(stack1, qmed);
	bottom = get_bottom(stack1, qmed);
	while (stack1->actualsize > 1)
	{
		low = get_low(stack2);
		while (pushed < 19)
		{
			if (top < bottom)
				while (top > 0)
				{
					ra(stack1);
					top--;
				}
			else
				while (bottom > 0)
				{
					rra(stack1);
					bottom--;
				}
			if (stack2->actualsize > 1)
			{
				while (stack2->stack[0] != low)
				{
					rb(stack2);
				}
			}
			if (stack1->stack[0] <= qmed)
			{
				pb(stack1, stack2);
				pushed++;
			}
			printf("\nVALUES\n-----------\n pushed: %d\n low: %d\n top:%d\n bot:%d\n med: %d\n s1: %d\n s1act: %d\n s1size: %d\n\n", pushed, get_low(stack1),top, bottom, qmed, stack1->stack[0], stack1->actualsize, stack1->stacksize);
			print_stacks(stack1, stack2);
			top = get_top(stack1, qmed);
			bottom = get_bottom(stack1, qmed);
			low = get_low(stack2);
			printf("\nVALUES\n-----------\n pushed: %d\n low: %d\n top:%d\n bot:%d\n med: %d\n s1: %d\n s1act: %d\n s1size: %d\n\n", pushed, get_low(stack1),top, bottom, qmed, stack1->stack[0], stack1->actualsize, stack1->stacksize);
		}
		qmed = get_big_median(stack1, stack1->actualsize);
		top = get_top(stack1, qmed);
		bottom = get_bottom(stack1, qmed);
		pushed = 0;
	}
	sort_big_b(stack1, stack2);
	return (0);
}

int	sort_big_b(t_stacks *stack1, t_stacks *stack2)
{
	int pushed;
	int high;
	int i;
	int j;
	int top;
	int bottom;

	i = 0;
	j = 0;
	pushed = 0;
	while (stack2->actualsize > 0)
	{
		high = get_high(stack2);
		top = get_b_top(stack2, high);
		bottom = get_b_bottom(stack2, high);
		if (top < bottom)
			while (top > 0)
			{
				ra(stack2);
				top--;
			}
		else
			while (bottom > 0)
			{
				rra(stack2);
				bottom--;
			}
		pa(stack1, stack2);
	}
	return (0);
}

int	sort_b(t_stacks *stack1, t_stacks *stack2)
{
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
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stack1;
	t_stacks	stack2;
	int			total;

	if (argc > 1)
		init_stack(argc, argv, &stack1, &stack2);
//	while (get_next_line(0, &line) > 0)
	print_stacks(&stack1, &stack2);
	solver500plus(&stack1, &stack2);
	//sorter function??
//	if (!(is_sorted(&stack1)) && stack2.actualsize == 0)
//		printf("VITUNJEES!\n");
//	else
//	{
//		printf("VOI EI, STACKIT ON NAIN:\n");
//		print_stacks(&stack1, &stack2);
//	}
	print_stacks(&stack1, &stack2);
	total = stack1.ainst + stack2.ainst;
	printf("\n--------------------\nAMOUNT OF INST : %d\n--------------------\n", total);
	//printer function??
	//error exit function
	return 0;
}

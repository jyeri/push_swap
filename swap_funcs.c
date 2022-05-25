#include "checker.h"
#include <stdio.h>

int	get_high(t_stacks *stack)
{
	int i;
	int hold;

	hold = 0;
	i = 0;
	while (i <= stack->actualsize)
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
	while (i < stack->actualsize)
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
	while (i <= stack->actualsize && stack->stack[i] >= qmed)
		i++;
	return (i);
}

int get_bottom(t_stacks *stack1, int qmed)
{
	int i;
	int j;

	j = stack1->actualsize - 1;
	i = 1;
	while (j > 0 && stack1->stack[j] >= qmed)
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
		i++;
		j--;
	}
	return (i);
}

int	get_big_median(t_stacks *stack, int size)
{
	int tmp[1000];
	int i = 0;
	int j;
	int med = 0;

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
	if (stack->actualsize < size + 1)
	{
		med = get_high(stack);
//		printf("MED IS NOW: %d\n", med);
//		sleep (1);
	}
	else
	{
		med = tmp[size];
//		printf("MED IS NOW: %d\n", med);
	}
	return(med);
}

int	sortsmallish(t_stacks *stack1, t_stacks *stack2, int low, int high)
{
	while (stack1->actualsize > 3)
	{
		if (stack1->stack[0] == high || stack1->stack[0] == low)
			pb(stack1, stack2);
		else
			ra(stack1);
	}
	solversmall(stack1, stack2);
	while(is_sorted(stack1) != 0 || stack2->actualsize > 0)
	{
		if (stack2->stack[0] == high)
		{
			pa(stack1, stack2);
			ra(stack1);
		}
		else
			pa(stack1, stack2);
	}
	return 0;
}

int	solversmall(t_stacks *stack1, t_stacks *stack2)
{
	int low;
	int high;

	low = get_low(stack1);
	high = get_high(stack1);
	if (stack1->actualsize < 4)
	{
		while(is_sorted(stack1))
		{
			if(stack1->stack[stack1->actualsize - 1] == high)
				sa(stack1);
			else if(stack1->stack[0] == high)
			{
				if (stack1->stack[stack1->actualsize - 1] == low)
				{
					sa(stack1);
					rra(stack1);
				}
				else
					ra(stack1);
			}
			else if (stack1->stack[0] == low)
			{
				sa(stack1);
				ra(stack1);
			}
			else
			{
				rra(stack1);
			}
		}
	}
	else
		sortsmallish(stack1, stack2, low, high);
	return (0);
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
	int chunksize;

	i = 0;
	j = 0;
	pushed = 0;
	if (stack1->actualsize > 499)
		chunksize = stack1->actualsize / 11;
	else if (stack1->actualsize > 99)
		chunksize = stack1->actualsize / 5;
	else
		chunksize = stack1->actualsize / 2;
	qmed = get_big_median(stack1, chunksize);
	top = get_top(stack1, qmed);
	bottom = get_bottom(stack1, qmed);
	while (stack1->actualsize > 1)
	{
		low = get_low(stack2);
		while (pushed < chunksize && stack1->actualsize >= 1)
		{
			if(stack1->actualsize < 2)
				pb(stack1, stack2);
			else if (top < bottom)
				while (top > 0)
				{
					if (top == 1 && stack2->actualsize > 1 && stack2->stack[0] < stack2->stack[1] && stack1->actualsize > 1)
						ss(stack1, stack2);
					else
					{
						if (stack2->stack[0] == low && stack2->actualsize > 1  && stack1->actualsize > 1)
							rr(stack1, stack2);
						else
							ra(stack1);
					}
					top--;
				}
			else
				while (bottom > 0)
				{
					if (top == 1 && stack2->actualsize > 1 && stack2->stack[0] < stack2->stack[1] && stack1->actualsize > 1)
						ss(stack1, stack2);
					else
					{
						if (stack2->stack[0] == low && stack2->actualsize > 1  && stack1->actualsize > 1)
							rrr(stack1, stack2);
						else
							rra(stack1);
					}
					bottom--;
				}
			if (stack1->stack[0] <= qmed)
			{
				pb(stack1, stack2);
				pushed++;
			}
//			printf("\nVALUES\n-----------\n pushed: %d\n low: %d\n top:%d\n bot:%d\n med: %d\n s1: %d\n s1act: %d\n s1size: %d\n\n", pushed, get_low(stack1),top, bottom, qmed, stack1->stack[0], stack1->actualsize, stack1->stacksize);
//			print_stacks(stack1, stack2);
			top = get_top(stack1, qmed);
			bottom = get_bottom(stack1, qmed);
			low = get_low(stack2);
//			printf("\nVALUES\n-----------\n pushed: %d\n low: %d\n top:%d\n bot:%d\n med: %d\n s1: %d\n s1act: %d\n s1size: %d\n\n", pushed, get_low(stack1),top, bottom, qmed, stack1->stack[0], stack1->actualsize, stack1->stacksize);
		}
		qmed = get_big_median(stack1, chunksize);
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
		if (top <= bottom)
			while (top > 0)
			{
				rb(stack2);
				top--;
			}
		else
			while (bottom > 0)
			{
				rrb(stack2);
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

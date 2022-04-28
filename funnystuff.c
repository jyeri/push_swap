#include "checker.h"
#include "stdio.h"

void	swap(t_stacks *stack)
{
	int	tmp;

	if (stack->actualsize > 2)
	{
		tmp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = tmp;
	}
}

void	rotate(t_stacks *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->stack[0];
	while (i < stack->actualsize - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[stack->actualsize - 1] = tmp;
}

void	reverse_rotate(t_stacks *stack)
{
	int	tmp;
	int i;

	i = stack->actualsize - 1;
	tmp = stack->stack[stack->actualsize - 1];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = tmp;
}

int	sa(t_stacks *stack1)
{
	//swap 2first elements of stack a
	//do nothing if array size of 1 or less
	swap(stack1);
	return (0);
}

int	sb(t_stacks *stack2)
{
	//swap 2first elements of stack a
	//do nothing if array size of 1 or less
	swap(stack2);
	return (0);
}

int ss(t_stacks *stack1, t_stacks *stack2)
{
	swap(stack1);
	swap(stack2);
	return (0);
}

int pa(t_stacks *stack1, t_stacks *stack2)
{
	int			tmp;
	int			j;

	j = stack1->actualsize;
	if (stack2->actualsize > 0)
	{
		tmp = stack2->stack[0];
		while (j > 0)
		{
			stack1->stack[j] = stack1->stack[j - 1];
			j--;
		}
		stack1->stack[0] = tmp;
		j = 0;
		while (j < stack2->actualsize - 1)
		{
			stack2->stack[j] = stack2->stack[j + 1];
			j++;
		}
		stack1->actualsize++;
		stack2->actualsize--;
	}
	return (0);
	//Take top of b -> top of A
	//nothing if B is empty
}

int pb(t_stacks *stack1, t_stacks *stack2)
{
	int			tmp;
	int			j;

	j = stack2->actualsize;
	if (stack1->actualsize > 0)
	{
		tmp = stack1->stack[0];
		while (j > 0)
		{
			stack2->stack[j] = stack2->stack[j - 1];
			j--;
		}
		stack2->stack[0] = tmp;
		j = 0;
		while (j < stack1->actualsize)
		{
			stack1->stack[j] = stack1->stack[j + 1];
			j++;
		}
		stack2->actualsize++;
		stack1->actualsize--;	
	}
	return (0);
	//Take top of A -> top of B
	//nothing if A is empty
}

int ra(t_stacks *stack1)
{
	rotate(stack1);
	return (0);
	//move every element is stack A up by one, First element -> Last element
}

int	rb(t_stacks *stack2)
{
	rotate(stack2);
	return (0);
	//move every element is stack B up by one, First element -> Last element
}

int	rr(t_stacks *stack1, t_stacks *stack2)
{
	rotate(stack1);
	rotate(stack2);
	return (0);
}

int	rra(t_stacks *stack1)
{
	reverse_rotate(stack1);
	return (0);
	//move every element is stack A down by one, LAST element -> FIRST element
}

int	rrb(t_stacks *stack2)
{
	reverse_rotate(stack2);
	return (0);
	//move every element is stack B down by one, LAST element -> FIRST element
}

int	rrr(t_stacks *stack1, t_stacks *stack2)
{
	reverse_rotate(stack1);
	reverse_rotate(stack2);
	return (0);
}

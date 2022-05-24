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
	stack1->ainst++;
	return (0);
	ft_putstr("sa\n");
}

int	sb(t_stacks *stack2)
{
	//swap 2first elements of stack a
	//do nothing if array size of 1 or less
	swap(stack2);
	stack2->ainst++;
	ft_putstr("sb\n");
	return (0);
}

int ss(t_stacks *stack1, t_stacks *stack2)
{
	stack1->ainst++;
	swap(stack1);
	swap(stack2);
	ft_putstr("ss\n");
	return (0);
}

int pa(t_stacks *stack1, t_stacks *stack2)
{
	int			tmp;
	int			j;

	stack1->ainst++;
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
	ft_putstr("pa\n");
	return (0);
	//Take top of b -> top of A
	//nothing if B is empty
}

int pb(t_stacks *stack1, t_stacks *stack2)
{
	int			tmp;
	int			j;

	stack1->ainst++;
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
	ft_putstr("pb\n");
	return (0);
	//Take top of A -> top of B
	//nothing if A is empty
}

int ra(t_stacks *stack1)
{
	stack1->ainst++;
	rotate(stack1);
	ft_putstr("ra\n");
	return (0);
	//move every element is stack A up by one, First element -> Last element
}

int	rb(t_stacks *stack2)
{
	stack2->ainst++;
	rotate(stack2);
	ft_putstr("rb\n");
	return (0);
	//move every element is stack B up by one, First element -> Last element
}

int	rr(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("rr\n");
	stack1->ainst++;
	rotate(stack1);
	rotate(stack2);
	return (0);
}

int	rra(t_stacks *stack1)
{
	ft_putstr("rra\n");
	stack1->ainst++;
	reverse_rotate(stack1);
	return (0);
	//move every element is stack A down by one, LAST element -> FIRST element
}

int	rrb(t_stacks *stack2)
{
	ft_putstr("rrb\n");
	stack2->ainst++;
	reverse_rotate(stack2);
	return (0);
	//move every element is stack B down by one, LAST element -> FIRST element
}

int	rrr(t_stacks *stack1, t_stacks *stack2)
{
	ft_putstr("rrr\n");
	stack1->ainst++;
	reverse_rotate(stack1);
	reverse_rotate(stack2);
	return (0);
}

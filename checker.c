int	main(int argc, char *argv)
{
	int	*stackA;
	int	*stackB;
	int	*tmp;
	int	nm;

	nm = 0
	while (argc--)
	{
		stackA[nm] = ft_atoi(argv[argc])
		nm++;
	}
	//check doubles on stack1
	//sorter function??
	//printer function??
	//error exit function

}

int	sa(int *stackA)
{
	//swap 2first elements of stack a
	//do nothing if array size of 1 or less
}

int	sb(int *stackB)
{
	//swap 2first elements of stack a
	//do nothing if array size of 1 or less
}

int ss(int *stackA, int *stackB)
{
	sa(stackA);
	sb(stackB);
}

int pa(int *stackA, int *stackB)
{
	//Take top of b -> top of A
	//nothing if B is empty
}

int pb(int *stackA, int *stackB)
{
	//Take top of A -> top of B
	//nothing if A is empty
}

int ra(int *stackA)
{
	//move every element is stack A up by one, First element -> Last element
}

int	rb(int *stackB)
{
	//move every element is stack B up by one, First element -> Last element
}

int	rr(int *stackA, int *stackB)
{
	ra(stackA);
	rb(stackB);
}

int	rra(int *stackA)
{
	//move every element is stack A down by one, LAST element -> FIRST element
}

int	rrb(int *stackB)
{
	//move every element is stack B down by one, LAST element -> FIRST element
}

int	rrr(int *stackA, int *stackB)
{
	rra(stackA);
	rrb(stackB);
}

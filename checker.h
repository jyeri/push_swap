#include "libft/libft.h"
#include "gnl/get_next_line.h"

typedef struct s_stacks
{
	int stack[10000];
	int	stacksize;
	int actualsize;

}	t_stacks;

int	sa(t_stacks *stack1);
int	sb(t_stacks *stack2);
int ss(t_stacks *stack1, t_stacks *stack2);
int pa(t_stacks *stack1, t_stacks *stack2);
int pb(t_stacks *stack1, t_stacks *stack2);
int ra(t_stacks *stack1);
int	rb(t_stacks *stack2);
int	rr(t_stacks *stack1, t_stacks *stack2);
int	rra(t_stacks *stack1);
int	rrb(t_stacks *stack2);
int	rrr(t_stacks *stack1, t_stacks *stack2);

//checker.c
void	init_stack(int argc, char **argv, t_stacks *stack1, t_stacks *stack2);
void	print_stacks(t_stacks *stack1, t_stacks *stack2);
int		is_sorted(t_stacks *stack);

//push_swap.c
int		solver(t_stacks *stack1, t_stacks *stack2);
int		sort_b(t_stacks *stack1, t_stacks *stack2);
# push_swap

Hive helsinki solo project called push_swap

## Objective

- Sort given data on a stack, using lowest number of actions possible
- 2 parts of the project:

Checker:
1. Takes integer arguments (./checker 3 2 1 0)
2. Reads instructions on STDOUT
3. Displays either OK or KO message, depending does instructions sort integers from low to high.

Push swap:
1. Takes integer arguments (./push_swap 2 1 3 6 5 8)
2. Using written algorithm prints smallest list of instructions needed to sort the stack.
3. In case of error, displays "Error" message

## Given istructions

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.

rrr : rra and rrb at the same time.

## Allowed library fuctions

◦ write
◦ read
◦ malloc
◦ free

## Visualizer

NOT MADE BY ME. Usage for visualizer is found on readme, in visualizer folder.

NAME = checker

NAME2 = push_swap

SRCS1 = checker.c bonus.c do_funcs1.c do_funcs2.c basic_functions1.c basic_functions2.c helpers1.c swap_funcs.c check_funcs.c funnystuff.c funnyswapstuff.c libftfuncs.c gnl/get_next_line.c

SRCS2 = push_swap.c bonus.c solverbig.c solversmall.c do_funcs1.c do_funcs2.c basic_functions1.c basic_functions2.c helpers1.c swap_funcs.c check_funcs.c funnystuff.c funnyswapstuff.c libftfuncs.c gnl/get_next_line.c

CFLAGS = gcc -Wall -Wextra -Werror -o

all: $(NAME) $(NAME2)
$(NAME):
	@$(MAKE) -C libft/ re
	$(CFLAGS) $(NAME) $(SRCS1) -L libft/ -lft

$(NAME2):
	$(CFLAGS) $(NAME2) $(SRCS2) -L libft/ -lft

clean:
	@$(MAKE) -C libft/ clean

fclean: fclean
	rm -f $(NAME)
	rm -f $(NAME2)
	@$(MAKE) -C libft/ fclean

re: fclean all
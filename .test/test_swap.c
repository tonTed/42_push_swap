#include "_test_header.h"

t_tabint	create_good_tab(char *str)
{
	char	**tabstr;

	tabstr = malloc(sizeof(char*) * 2);
	tabstr[0] = "testing";
	tabstr[1] = str;
	return (create_tab(tabstr, 2));
}

void	test_swap(t_test test)
{
	size_t		errors = 0;
	size_t		tests = 0;
	t_stack		stack_a;
	t_stack		stack_b;
	t_tabint	tabint;

	printf(MAG "\n-- %s:" RESET, __func__);
	tabint = create_good_tab("0 2 5 6 1");
	stack_a = create_stack(tabint, false, 'a');
	stack_b = create_stack(tabint, true, 'b');

	// __1
	tests++;
	// returned = ft_strndup(NULL, 3);
	// expected = "";
	// if (strcmp(expected, returned))
	// 	{printf(YEL "\n1_\texpected: %s\t - returned: %s" RESET, expected, returned); errors++;}
	// free(returned);

	put_errors_func(errors, tests, test);
}
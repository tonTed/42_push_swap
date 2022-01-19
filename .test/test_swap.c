#include "test_header.h"

void	test_swap(t_test test)
{
	size_t		errors = 0;
	size_t		tests = 0;

	printf(MAG "\n-- %s:" RESET, __func__);
	// __1
	tests++;
	// returned = ft_strndup(NULL, 3);
	// expected = "";
	// if (strcmp(expected, returned))
	// 	{printf(YEL "\n1_\texpected: %s\t - returned: %s" RESET, expected, returned); errors++;}
	// free(returned);

	put_errors_func(errors, tests, test);
}
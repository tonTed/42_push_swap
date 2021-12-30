/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:36:17 by tonted            #+#    #+#             */
/*   Updated: 2021/12/29 19:54:53 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

void	test_sample(t_test test)
{
	size_t errors = 0;
	size_t tests = 0;

	printf(MAG "\n----- NAME:" RESET);
	// 1
	// (*test)++;
	// returned = ft_strndup(NULL, 3);
	// expected = "";
	// if (strcmp(expected, returned))
	// 	{printf(YEL "\n1_\texpected: %s\t - returned: %s" RESET, expected, returned); errors++;}
	// free(returned);

	//END
	*test.errors += errors;
	*test.tests += tests;
	if (errors)
		printf(RED "\nErrors: %zu/%zu\n" RESET,errors, tests);
	else
		printf(GRN " PASSED" RESET);
}

t_test	new_t_test()
{
	t_test	test;

	test.tests = malloc(sizeof(size_t));
	*test.tests = 0;
	test.errors = malloc(sizeof(size_t));
	*test.errors = 0;
	return (test);
}

int main()
{
	t_test	test;

	test = new_t_test();
	return 0;
}


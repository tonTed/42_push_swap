/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:36:17 by tonted            #+#    #+#             */
/*   Updated: 2022/01/18 20:35:50 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

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

int main()
{
	t_test	test;
	(void) test;

	return 0;
}


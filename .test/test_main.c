/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:36:17 by tonted            #+#    #+#             */
/*   Updated: 2022/01/19 12:11:41 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_push_swap.h"

t_test	config()
{
	t_test	test;

	test.errors = (size_t*)malloc(sizeof(size_t));
	test.tests = (size_t*)malloc(sizeof(size_t));
	return (test);

}

void	put_errors_main(size_t errors, size_t tests)
{
	if (errors)
		printf(BRED "\n\nErrors: %zu/%zu\n" RESET,errors, tests);
	else
		printf(BGRN "\n\nPASSED\n" RESET);
}

int main()
{
	t_test	test;

	test = config();
	printf(BBLU "\n----- UNIT TESTS FOR PUSH_SWAP:" RESET);

	test_swap(test);
	
	put_errors_main(*test.errors, *test.tests);
	return (0);
}


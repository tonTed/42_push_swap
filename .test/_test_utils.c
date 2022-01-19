/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:21:08 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/19 12:26:09 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_header.h"

void	put_errors_func(size_t errors, size_t tests, t_test test)
{
	*test.errors += errors;
	*test.tests += tests;
	if (errors)
		printf(RED "\nErrors: %zu/%zu\n" RESET,errors, tests);
	else
		printf(GRN " PASSED" RESET);
}

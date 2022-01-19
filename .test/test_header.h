/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:43:45 by tonted            #+#    #+#             */
/*   Updated: 2022/01/19 11:25:22 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HEADER_H
# define TEST_HEADER_H

# include <stdio.h>
# include "colors.h"

// include header of project
# include "push_swap.h"

typedef struct s_test
{
	size_t	*tests;
	size_t	*errors;
}				t_test;

void	put_errors_func(size_t errors, size_t tests, t_test test);

# endif
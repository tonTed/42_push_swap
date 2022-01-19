/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 13:43:45 by tonted            #+#    #+#             */
/*   Updated: 2022/01/18 20:47:57 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HEADER_H
# define TEST_HEADER_H

# include <stdio.h>
# include "colors.h"

// include header of project
# include "push_swap.h"
# include "test_push_swap.h"


typedef struct s_test
{
	size_t	*tests;
	size_t	*errors;
}				t_test;

t_test	TEST;

# endif
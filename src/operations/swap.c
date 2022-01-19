/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:59:37 by tonted            #+#    #+#             */
/*   Updated: 2022/01/19 15:22:28 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the first 2 elements at the top of stack a. Do nothing if there is only
// one or no elements).
void	swap(t_stack stack)
{
	if ((*stack.last_i >= 1))
	{
		ft_swap(&stack.tab.tab[0], &stack.tab.tab[1]);
		print_op("s", stack.name);
	}
}

// swap the first 2 elements at the top of stack a. Do nothing if there is only
// one or no elements).
void	sswap(t_stack stack_1, t_stack stack_2)
{
	ft_swap(&stack_1.tab.tab[0], &stack_1.tab.tab[1]);
	ft_swap(&stack_2.tab.tab[0], &stack_2.tab.tab[1]);
	ft_putendl_fd("ss", 1);
	put_stack(stack_1, stack_2);
}

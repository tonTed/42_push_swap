/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:56:26 by tonted            #+#    #+#             */
/*   Updated: 2022/01/19 15:23:49 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_rev_rotate(t_stack stack)
{
	int	tmp;

	tmp = stack.tab.tab[*stack.last_i];
	move_down(stack);
	stack.tab.tab[0] = tmp;
}

// shift down all elements of stack a by 1. The last element becomes the first
// one.
void	rev_rotate(t_stack stack)
{
	if (!(*stack.last_i < 2))
	{
		p_rev_rotate(stack);
		print_op("rr", stack.name);
	}
}

// shift down all elements of stack a by 1. The last element becomes the first
// one.
void	rev_rrotate(t_stack stack_1, t_stack stack_2)
{
	p_rev_rotate(stack_1);
	p_rev_rotate(stack_2);
	ft_putendl_fd("rrr", 1);
	put_stack(stack_1, stack_2);
}

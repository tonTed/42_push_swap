/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:56:26 by tonted            #+#    #+#             */
/*   Updated: 2022/01/19 15:39:50 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_rotate(t_stack stack)
{
	int	tmp;

	tmp = stack.tab.tab[0];
	move_up(stack);
	stack.tab.tab[*stack.last_i] = tmp;
}

// shift up all elements of stack a by 1. The first element becomes the last
// one.
void	rotate(t_stack stack)
{
	if (!(*stack.last_i < 2))
	{
		p_rotate(stack);
		print_op("r", stack.name);
	}
}

// shift up all elements of stack a by 1. The first element becomes the last
// one.
void	rrotate(t_stack stack_1, t_stack stack_2)
{
	p_rotate(stack_1);
	p_rotate(stack_2);
	print_op("r", 'r');
	put_stack(stack_1, stack_2);
}

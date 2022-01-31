/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:56:26 by tonted            #+#    #+#             */
/*   Updated: 2022/01/30 17:41:20 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_rotate(t_stack *stack)
{
	int	tmp;

	tmp = (*stack).tab[0];
	if ((*stack).i_end < 2)
		(*stack).tab[0] = (*stack).tab[(*stack).i_end];
	else
		move_up(stack);
	(*stack).tab[(*stack).i_end] = tmp;
}

// shift up all elements of stack a by 1. The first element becomes the last
// one.
void	rotate(t_stack *stack)
{
	if (!((*stack).i_end < 1))
	{
		p_rotate(stack);
		print_op("r", (*stack).name);
	}
}

// shift up all elements of stack a by 1. The first element becomes the last
// one.
void	rrotate(t_stack *stack_1, t_stack *stack_2)
{
	p_rotate(stack_1);
	p_rotate(stack_2);
	print_op("r", 'r');
}

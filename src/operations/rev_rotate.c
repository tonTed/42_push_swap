/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:56:26 by tonted            #+#    #+#             */
/*   Updated: 2022/01/30 17:41:33 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_rev_rotate(t_stack *stack)
{
	int	tmp;

	tmp = (*stack).tab[(*stack).i_end];
	if ((*stack).i_end < 2)
		(*stack).tab[(*stack).i_end] = (*stack).tab[0];
	else
		move_down(stack);
	(*stack).tab[0] = tmp;
}

// shift down all elements of stack a by 1. The last element becomes the first
// one.
void	rev_rotate(t_stack *stack)
{
	if (!((*stack).i_end < 1))
	{
		p_rev_rotate(stack);
		print_op("rr", (*stack).name);
	}
}

// shift down all elements of stack a by 1. The last element becomes the first
// one.
void	rev_rrotate(t_stack *stack_1, t_stack *stack_2)
{
	p_rev_rotate(stack_1);
	p_rev_rotate(stack_2);
	ft_putendl_fd("rrr", 1);
}

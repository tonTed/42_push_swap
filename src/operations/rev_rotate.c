/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:56:26 by tonted            #+#    #+#             */
/*   Updated: 2021/12/27 22:36:42 by tonted           ###   ########.fr       */
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

void	rev_rotate(t_stack stack)
{
	if (!(*stack.last_i < 2))
	{
		p_rev_rotate(stack);
		print_op("rr", stack.name);
	}
}

void	rev_rrotate(t_stack stack_1, t_stack stack_2)
{
	p_rev_rotate(stack_1);
	p_rev_rotate(stack_2);
	ft_putendl_fd("rrr", 1);
}

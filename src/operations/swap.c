/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:59:37 by tonted            #+#    #+#             */
/*   Updated: 2022/01/30 11:27:57 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the first 2 elements at the top of stack a. Do nothing if there is only
// one or no elements).
void	swap(t_stack stack)
{
	if ((stack.i_end >= 1))
	{
		ft_swap(&stack.tab[0], &stack.tab[1]);
		print_op("s", stack.name);
	}
}

// swap the first 2 elements at the top of stack a. Do nothing if there is only
// one or no elements).
void	sswap(t_stack stack_1, t_stack stack_2)
{
	ft_swap(&stack_1.tab[0], &stack_1.tab[1]);
	ft_swap(&stack_2.tab[0], &stack_2.tab[1]);
	ft_putendl_fd("ss", 1);
}

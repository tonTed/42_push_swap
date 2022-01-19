/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:59:37 by tonted            #+#    #+#             */
/*   Updated: 2022/01/18 21:02:12 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack stack)
{
	if ((*stack.last_i >= 1))
	{
		ft_swap(&stack.tab.tab[0], &stack.tab.tab[1]);
		print_op("s", stack.name);
	}
}

void	sswap(t_stack stack_1, t_stack stack_2)
{
	ft_swap(&stack_1.tab.tab[0], &stack_1.tab.tab[1]);
	ft_swap(&stack_2.tab.tab[0], &stack_2.tab.tab[1]);
	ft_putendl_fd("ss", 1);
}

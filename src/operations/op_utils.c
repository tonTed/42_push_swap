/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:58:29 by tonted            #+#    #+#             */
/*   Updated: 2022/01/26 18:53:15 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *op, char stack)
{
	ft_putstr_fd(op, 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	move_down(t_stack stack)
{
	ssize_t	i;

	i = *stack.last_i;
	while (i > 0)
	{
		stack.tab.tab[i] = stack.tab.tab[i - 1];
		i--;
	}
}

void	move_up(t_stack stack)
{
	ssize_t	i;

	i = 0;
	while (i <= *stack.last_i)
	{
		stack.tab.tab[i] = stack.tab.tab[i + 1];
		i++;
	}
}

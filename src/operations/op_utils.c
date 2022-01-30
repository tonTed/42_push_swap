/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:58:29 by tonted            #+#    #+#             */
/*   Updated: 2022/01/30 11:23:00 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *op, char stack)
{
	ft_putstr_fd(op, 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	move_down(t_stack s)
{
	ssize_t	i;

	i = s.i_end;
	while (i > 0)
	{
		s.tab[i] = s.tab[i - 1];
		i--;
	}
}

void	move_up(t_stack s)
{
	ssize_t	i;

	i = 0;
	while (i <= s.i_end)
	{
		s.tab[i] = s.tab[i + 1];
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_first_second.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:09:22 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/19 16:11:46 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_first_bigger_second(int *tab, ssize_t len)
{
	return (tab[0] > tab[len - 1]);
}

bool	is_firsts_big_second(t_stack stack_a, t_stack stack_b)
{
	if (is_first_bigger_second(stack_a.tab.tab, *stack_a.last_i + 1)
		&& !(is_first_bigger_second(stack_b.tab.tab, *stack_b.last_i + 1)))
	{
		sswap(stack_a, stack_b);
		return (true);
	}
	return (false);
}

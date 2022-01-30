/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:47:41 by tonted            #+#    #+#             */
/*   Updated: 2022/01/29 21:47:19 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO refactor hard_code name
static bool	one_mov(t_stack stack, char *mov)
{
	size_t	i_s;
	size_t	i_b;

	i_s = 0;
	if (!ft_strncmp(mov, "ss", 2))
		i_b = 1;
	else if (!ft_strncmp(mov, "rrr", 3))
		i_b = *stack.last_i;
	if (stack.name == 'a' && *stack.last_i > 0)
	{
		if (stack.tab.tab[i_s] > stack.tab.tab[i_b])
			return (true);
	}
	else if (stack.name == 'b' && *stack.last_i > 0)
	{
		if (stack.tab.tab[i_s] < stack.tab.tab[i_b])
			return (true);
	}
	return (false);
}

static bool	two_mov(t_stack s1, t_stack s2, char *mov)
{
	if (one_mov(s1, mov) && one_mov(s2, mov))
		return (true);
	return (false);
}

bool	to_swap(t_stack s1, t_stack s2)
{
	while (1)
	{
		if (two_mov(s1, s2, "ss"))
			sswap(s1, s2);
		else
			return (false);
	}
}

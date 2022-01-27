/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:47:41 by tonted            #+#    #+#             */
/*   Updated: 2022/01/27 16:06:11 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO refactor hard_code name
static bool	simple_swap(t_stack stack)
{
	if (stack.name == 'a' && *stack.last_i > 0)
	{
		if (stack.tab.tab[0] > stack.tab.tab[1])
			return (true);
	}
	else if (stack.name == 'b' && *stack.last_i > 0)
	{
		if (stack.tab.tab[0] < stack.tab.tab[1])
			return (true);
	}
	return (false);
}

static bool	dual_swap(t_stack sa, t_stack sb)
{
	if (simple_swap(sa) && simple_swap(sb))
		return (true);
	return (false);
}

bool	to_swap(t_stack sa, t_stack sb)
{
	if (dual_swap(sa, sb))
		sswap(sa, sb);
	else if (simple_swap(sa))
		swap(sa);
	else if (simple_swap(sb))
		swap(sb);
	else
		return (false);
	// put_stack(sa, sb);
	return (true);
}

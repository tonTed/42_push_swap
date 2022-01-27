/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/26 19:21:17 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_med(t_stack stack)
{
	return (*stack.last_i / 2);
}

// TODO refactor hard_code name
bool	simple_swap(t_stack stack)
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

bool	dual_swap(t_stack sa, t_stack sb)
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
	put_stack(sa, sb);
	return (true);
}

void	algo_big(t_stack sa, t_stack sb)
{
	ssize_t	med;
	int		fu;

	med = get_med(sa);
	fu = (sa.tab.size - *sa.last_i - 1);
	if (*sa.last_i == 2)
	{
		algo_3(sa);
		return;
	}
	while (*sa.last_i > med)
	{
		if (to_swap(sa, sb))
			continue ;
		else if (sa.tab.tab[0] <= (med + fu))
			push(sa, sb);
		else
			rotate(sa);
		put_stack(sa, sb);
		sleep(1);
	}
	printf("recursion\n");
	algo_big(sa, sb);
}
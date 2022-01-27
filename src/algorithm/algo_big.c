/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/27 17:02:38 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_big_first(t_stack sa, t_stack sb)
{
	ssize_t	med;
	int		fu;

	med = get_med(sa);
	// TODO do function for get the last bigger number to push 
	if (*sa.last_i % 2 == 0)
		fu = (sa.tab.size - *sa.last_i - 2);
	else
		fu = (sa.tab.size - *sa.last_i - 1);
	if (*sa.last_i == 4)
	{
		algo_5(sa, sb);
		return ;
	}
	while (*sa.last_i > med && *sa.last_i > 4)
	{
		if (to_swap(sa, sb))
			continue ;
		else if (sa.tab.tab[0] <= (med + fu))
			push(sa, sb);
		else
			rotate(sa);
		// put_stack(sa, sb);
	}
	algo_big_first(sa, sb);
}

bool	next_push(t_stack src, t_stack dst)
{
	ssize_t	i_big;

	i_big = where_is_bigger(src);
	if (*src.last_i < 2 || i_big < (*src.last_i / 2))
		rotate(src);
	else
		rev_rotate(src);
	// put_stack(dst, src); 
	if (src.tab.tab[0] + 1 == dst.tab.tab[0])
		return (true);
	return (false);
}

void	algo_end(t_stack sa, t_stack sb)
{
	while (sa.tab.tab[0] - 1 == sb.tab.tab[0])
	{
		push(sb, sa);
		// put_stack(sa, sb);
	}
	if (*sb.last_i < 0)
		return ;
	while (!next_push(sb, sa))
		continue ;
	algo_end(sa, sb);
}

void	algo_big(t_stack sa, t_stack sb)
{
	algo_big_first(sa, sb);
	// put_stack(sa, sb);
	algo_end(sa, sb);
	return ;
}

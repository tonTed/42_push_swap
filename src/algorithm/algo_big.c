/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/27 14:40:25 by tblanco          ###   ########.fr       */
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
	if (*sa.last_i == 2)
	{
		algo_3(sa);
		return ;
	}
	while (*sa.last_i > med && *sa.last_i > 2)
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

bool	is_next(t_stack sa, t_stack sb)
{
	while (sa.tab.tab[0] - 1 != sb.tab.tab[0] && *sb.last_i != - 1)
	{
		if (sa.tab.tab[0] - 1 == sb.tab.tab[0])
		{	
			rotate(sb);
			// put_stack(sa, sb);
			return true;
		}
		rotate(sb);
		// put_stack(sa, sb);
	}
	return (false);
}

bool	is_next_r(t_stack sa, t_stack sb)
{
	while (sa.tab.tab[0] - 1 != sb.tab.tab[0] && *sb.last_i != - 1)
	{
		if (sa.tab.tab[0] - 1 == sb.tab.tab[0])
		{	
			rev_rotate(sb);
			// put_stack(sa, sb);
			return true;
		}
		rev_rotate(sb);
		// put_stack(sa, sb);
	}
	return (false);
}

void	algo_end(t_stack sa, t_stack sb)
{
	ssize_t	i_big;

	if (*sb.last_i < 0)
		return ;
	while (sa.tab.tab[0] - 1 == sb.tab.tab[0])
	{
		push(sb, sa);
		// put_stack(sa, sb);
	}
	i_big = where_is_bigger(sb);
	if (i_big < *sb.last_i / 2)
		is_next(sa, sb);
	else
		is_next_r(sa, sb);
	algo_end(sa, sb);
}

void	algo_big(t_stack sa, t_stack sb)
{
	algo_big_first(sa, sb);
	// put_stack(sa, sb);
	algo_end(sa, sb);
	return ;
}

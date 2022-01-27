/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/26 23:19:20 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_big_first(t_stack sa, t_stack sb)
{
	ssize_t	med;
	int		fu;

	med = get_med(sa);
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

void	algo_end(t_stack sa, t_stack sb)
{
	ssize_t	i_big;

	if (*sb.last_i < 0)
		return ;
	while (sa.tab.tab[0] -1 == sb.tab.tab[0])
		push(sb, sa);
	i_big = where_is_bigger(sb);
	if (i_big < *sb.last_i / 2)
	{
		while (sa.tab.tab[0] - 1 != sb.tab.tab[0])
		{
			if (sa.tab.tab[0] - 1 == sb.tab.tab[0])
			{	
				rotate(sb);
				return ;
			}
			rotate(sb);
		}
	}
	else
	{
		while (sa.tab.tab[0] -1 != sb.tab.tab[0])
		{
			if (sa.tab.tab[0] - 1 == sb.tab.tab[0])
			{	
				rev_rotate(sb);
				return ;
			}
			rev_rotate(sb);
		}
	}
	algo_end(sa, sb);
}

void	algo_big(t_stack sa, t_stack sb)
{
	algo_big_first(sa, sb);
	put_stack(sa, sb);
	algo_end(sa, sb);
}

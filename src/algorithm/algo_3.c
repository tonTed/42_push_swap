/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:15:07 by tonted            #+#    #+#             */
/*   Updated: 2022/01/24 13:42:58 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	firs_step(t_stack sa)
{
	if (is_bigger_tab(sa.tab.tab, sa.tab.size, sa.tab.tab[0]))
		rotate(sa);
	else if (is_smaller_tab(sa.tab.tab, sa.tab.size, sa.tab.tab[1])
	|| is_bigger_tab(sa.tab.tab, sa.tab.size, sa.tab.tab[1]))
		swap(sa);
	else if (is_smaller_tab(sa.tab.tab, sa.tab.size, sa.tab.tab[*sa.last_i]))
		rev_rotate(sa);
	else
		return (false)
	return (true)
}

void	algo_3(t_stack sa)
{
	first_step(sa);
	put_stack(sa, sa);
	if (ft_issorted(sa.tab.tab, sa.tab.size))
		return ;
	else 
		algo_3(sa);
}

void	algo_5(t_stack sa,t_stack sb)
{
	if (!first_step(sa))
		push(sa, sb);
	if ()
	put_stack(sa, sb);
	sleep(1);
	if (sb.last_i < 0 && ft_issorted(sa.tab.tab, sa.tab.size))
		return ;
	else 
		algo_5(sa, sb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:15:07 by tonted            #+#    #+#             */
/*   Updated: 2022/01/27 16:59:04 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if is the bigger in the tab
static bool	is_bigger_tab(t_stack stack, int num)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = *stack.last_i + 1;
	while (i < len)
		if (stack.tab.tab[i++] > num)
			return (false);
	return (true);
}

// check if is the bigger in the tab
static bool	is_smaller_tab(t_stack stack, int num)
{
	size_t	i;
	size_t	len;

	len = *stack.last_i + 1;
	i = 0;
	while (i < len)
		if (stack.tab.tab[i++] < num)
			return (false);
	return (true);
}

void	algo_3(t_stack sa)
{
	if (is_bigger_tab(sa, sa.tab.tab[0]))
		rotate(sa);
	else if (is_bigger_tab(sa, sa.tab.tab[1]))
		rev_rotate(sa);
	if (is_smaller_tab(sa, sa.tab.tab[1]))
		swap(sa);
}

void	algo_5(t_stack sa, t_stack sb)
{
	if (*sa.last_i == 2)
	{
		algo_3(sa);
		if (sb.tab.tab[0] < sb.tab.tab[1])
			swap(sb);
		push(sb, sa);
		push(sb, sa);
		return ;
	}
	else if (is_smaller_tab(sa, sa.tab.tab[0]))
		push(sa, sb);
	// TODO condition for rev_rotate
	else
		rotate(sa);
	if (*sa.last_i == 4 && ft_issorted(sa.tab.tab, 5))
		return ;
	else
		algo_5(sa, sb);
}

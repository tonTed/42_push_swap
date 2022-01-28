/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:15:07 by tonted            #+#    #+#             */
/*   Updated: 2022/01/28 10:15:26 by tblanco          ###   ########.fr       */
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

void	algo_5(t_stacks stacks)
{
	if (*stacks.sa->last_i == 2)
	{
		algo_3(*stacks.sa);
		if (stacks.sb->tab.tab[0] < stacks.sb->tab.tab[1])
			swap(*stacks.sb);
		push(*stacks.sb, *stacks.sa);
		push(*stacks.sb, *stacks.sa);
		return ;
	}
	else if (is_smaller_tab(*stacks.sa, stacks.sa->tab.tab[0]))
		push(*stacks.sa, *stacks.sb);
	// TODO condition for rev_rotate
	else
		rotate(*stacks.sa);
	if (*stacks.sa->last_i == 4 && ft_issorted(stacks.sa->tab.tab, 5))
		return ;
	else
		algo_5(stacks);
}

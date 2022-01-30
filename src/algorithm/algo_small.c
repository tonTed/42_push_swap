/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:15:07 by tonted            #+#    #+#             */
/*   Updated: 2022/01/30 11:40:33 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if is the bigger in the tab
static bool	is_bigger_tab(t_stack stack, int num)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = stack.i_end + 1;
	while (i < len)
		if (stack.tab[i++] > num)
			return (false);
	return (true);
}

// check if is the bigger in the tab
static bool	is_smaller_tab(t_stack stack, int num)
{
	size_t	i;
	size_t	len;

	len = stack.i_end + 1;
	i = 0;
	while (i < len)
		if (stack.tab[i++] < num)
			return (false);
	return (true);
}

void	algo_3(t_stack a)
{
	if (is_bigger_tab(a, a.tab[0]))
		rotate(a);
	else if (is_bigger_tab(a, a.tab[1]))
		rev_rotate(a);
	if (is_smaller_tab(a, a.tab[1]))
		swap(a);
}

void	algo_5(t_stacks stacks)
{
	if (stacks.a->i_end == 2)
	{
		algo_3(*stacks.a);
		if (stacks.b->tab[0] < stacks.b->tab[1])
			swap(*stacks.b);
		push(stacks.b, stacks.a);
		push(stacks.b, stacks.a);
		return ;
	}
	else if (is_smaller_tab(*stacks.a, stacks.a->tab[0]))
		push(stacks.a, stacks.b);
	// TODO condition for rev_rotate
	else
		rotate(*stacks.a);
	put_stack(stacks);
	if (stacks.a->i_end == 4 && ft_issorted(stacks.a->tab, 5))
		return ;
	else
		algo_5(stacks);
}

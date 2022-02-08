/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:15:07 by tonted            #+#    #+#             */
/*   Updated: 2022/02/08 13:44:13 by tblanco          ###   ########.fr       */
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

void	algo_3(t_stacks s)
{
	if (is_bigger_tab(*s.a, s.a->tab[0]))
	{
		if (s.b->i_end > 0 && s.b->tab[0] > s.b->tab[1])
			rrotate(s.a, s.b);
		else
			rotate(s.a);
	}
	else if (is_bigger_tab(*s.a, s.a->tab[1]))
	{
		if (s.b->i_end > 0 && s.b->tab[0] > s.b->tab[1])
			rev_rrotate(s.a, s.b);
		else
			rev_rotate(s.a);
	}
	if (is_smaller_tab(*s.a, s.a->tab[1]))
	{
		if (s.b->i_end > 0 && s.b->tab[0] > s.b->tab[1])
			sswap(s.a, s.b);
		else
			swap(s.a);
	}
}

void	algo_5(t_stacks s)
{
	int	min;

	min = get_min(*s.a);
	if (s.a->i_end == 2)
	{
		algo_3(s);
		push(s.b, s.a);
		push(s.b, s.a);
		if (s.a->tab[0] > s.a->tab[1])
			swap(s.a);
		return ;
	}
	else if (s.a->tab[0] == min || (s.a->tab[0] == min + 1 && s.b->i_end > 0))
		push(s.a, s.b);
	else if (s.a->tab[s.a->i_end] == min || (s.a->tab[s.a->i_end] == min + 1
			&& s.b->i_end > 0))
		rev_rotate(s.a);
	else
		rotate(s.a);
	put_stack(s);
	if (s.a->i_end == 4 && ft_issorted(s.a->tab, 5))
		return ;
	else
		algo_5(s);
}

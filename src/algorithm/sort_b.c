/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:12:59 by tonted            #+#    #+#             */
/*   Updated: 2022/02/05 10:04:37 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_split_b(t_stacks s, int min, int max)
{
	if (s.a->tab[0] == *s.max_sort)
		;
	else if (s.b->tab[0] == *s.max_sort)
		push(s.b, s.a);
	else if (s.b->tab[s.b->i_end] == *s.max_sort)
	{
		rev_rotate(s.b);
		push(s.b, s.a);
	}
	else if (s.b->tab[1] == *s.max_sort
		&& (s.b->tab[0] == *s.max_sort + 1 || s.b->tab[s.b->i_end] == *s.max_sort + 1))
	{
		if (s.a->tab[0] > s.a->tab[1] && s.a->tab[1] != 0)
			sswap(s.a, s.b);
		else
			swap(s.b);
		push(s.b, s.a);
	}
	else
		return ;
	(*s.max_sort)++;
	if (!is_between(s.b->tab[0], min, max))
		rrotate(s.a, s.b);
	else
		rotate(s.a);
	opti_split_b(s, min, max);
}

void	opti_sort_b(t_stacks s)
{
	if (s.a->tab[0] == *s.max_sort)
		;
	else
		return ;
	(*s.max_sort)++;
	rotate(s.a);
	opti_sort_b(s);
}

void	push_to_b(t_stacks s, int min, int max)
{
	put_stack(s);
	if (!range_in_tab(*s.a, min, max))
	{
		sort_b(s, min);
		return ; 
	}
	// if (!range_in_tab(*s.a, min,(max - min) / 2 + min))
	// {
	// 	sort_b(s, min);
	// 	return ;
	// }
	if (s.a->tab[0] == *s.max_sort)
	{
		o_rotate_b(s, (max - min) / 2);
		(*s.max_sort)++;
		min++;
	}
	else if (is_between(s.a->tab[0], min, max))
		push(s.a, s.b);
	push_to_b(s, min, max);
}

void	split_b(t_stacks s, int min, int max)
{
	put_stack(s);
	if (s.b->i_end <= 11 && sort_to_a(s))
		return ;
	if (!range_in_tab(*s.b, min, max))
		return ;
	opti_split_b(s, min, max);
	if (is_between(s.b->tab[0], min, max))
		push(s.b, s.a);
	else
		rotate(s.b);
	split_b(s, min, max);
}

void	sort_b(t_stacks s, int min)
{
	int	max;
	put_stack(s);
	if (s.b->i_end <= 0)
		return ;
	max = get_max(*s.b);
	while (is_in_tab(*s.max_sort, *s.a))
		push(s.a, s.b);
	split_b(s, get_med(*s.b), max);
	sort_b(s, min);
	opti_sort_b(s);
	push_to_b(s, *s.max_sort, max);
}

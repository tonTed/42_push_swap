/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:16:09 by tonted            #+#    #+#             */
/*   Updated: 2022/02/05 10:05:51 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_is_next(t_stacks s)
{
	if (s.a->tab[0] == *s.max_sort)
	{
		(*s.max_sort)++;
		if (s.b->tab[1] == get_max(*s.b) || s.b->tab[1] == (*s.max_sort))
			rrotate(s.a, s.b);
		else 
			rotate(s.a);
	}
}

static void	opti_sort_to_a(t_stacks s)
{
	put_stack(s);
	if (s.a->tab[0] == *s.max_sort)
		;
	else if (s.b->i_end > 0 && (s.b->tab[0] == *s.max_sort 
			|| s.b->tab[0] == get_max(*s.b)))
		push(s.b, s.a);
	else if (s.b->i_end > 0 && s.b->tab[s.b->i_end] == get_max(*s.b)
		&& (s.b->tab[1] == *s.max_sort || s.b->tab[1] == get_max(*s.b) - 1))
	{
		rev_rotate(s.b);
		push(s.b, s.a);
	}
	else if (s.b->i_end > 0 && s.b->tab[1] == get_max(*s.b)
			&& (s.b->tab[0] == *s.max_sort || s.b->tab[0] == get_max(*s.b) - 1))
	{
		if (s.a->tab[0] > s.a->tab[1] && s.a->tab[1] != 0)
			sswap(s.a, s.b);
		else
			swap(s.b);
		push(s.b, s.a);
	}
	else
		return ;
	rotate_is_next(s);
	opti_sort_to_a(s);
}

int		sort_to_a(t_stacks s)
{
	if (s.b->i_end < 0)
		return (1);
	opti_sort_to_a(s);
	if (s.b->tab[0] == get_max(*s.b))
		push(s.b, s.a);
	else if (next_to_push_to_a(s) > s.b->i_end / 2)
		rev_rotate(s.b);
	else
		rotate(s.b);
	sort_to_a(s);
	return (1);
}

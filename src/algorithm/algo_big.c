/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/02/01 19:06:26 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stacks s, int *min, int max);

void	dual_swap(t_stacks s)
{
	if (s.a->tab[0] > s.a->tab[1] && s.b->tab[0] < s.b->tab[1] && s.b->i_end > 0)
		sswap(s.a, s.b);
}

void	push_next(int nb, t_stack *src, t_stack *dst)
{
	ssize_t	i_nb;

	if (nb == -1)
		return ;
	i_nb = get_index(nb, *src);
	if (i_nb == -1)
		return ;
	if (i_nb < src->i_end / 2)
	{
		while (src->tab[0] != nb)
		{
			if (src->tab[0] + 1 == dst->tab[0])
				push(src, dst);
			rotate(src);
		}
	}
	else
	{
		while (src->tab[0] != nb)
		{
			if (src->tab[0] + 1 == dst->tab[0])
				push(src, dst);
			rev_rotate(src);
		}
	}
	push(src, dst);
}

void	next_sort(t_stacks s, int *min)
{
	if (s.a->tab[0] == *s.max_sort)
		;
	else if (s.a->tab[1] == *s.max_sort)
		swap(s.a);
	else if (s.b->tab[0] == *s.max_sort)
		push(s.b, s.a);
	else
		return ;
	rotate(s.a);
	(*s.max_sort)++;
	next_sort(s, min);
}

void	next_sort_s(t_stacks s, int *min)
{
	if (s.a->tab[0] == *s.max_sort)
		;
	else if (s.a->tab[1] == *s.max_sort)
		swap(s.a);
	else if (s.b->tab[1] == *s.max_sort)
	{
		swap(s.b);
		push(s.b, s.a);
	}
	else if (s.b->tab[0] == *s.max_sort)
		push(s.b, s.a);
	else
		return ;
	rotate(s.a);
	(*s.max_sort)++;
	min++;
	next_sort_s(s, min);
}

void	sort(t_stacks s, int *min, int max)
{
	next_sort_s(s, min);
	if (*s.max_sort >= max)
		return ;
	if (is_in_tab(*s.max_sort, *s.a))
		push(s.a, s.b);
	else if (s.b->tab[0] == get_max(*s.b))
		push(s.b, s.a);
	else
		push_next(*s.max_sort, s.b, s.a);
	sort(s, min, max);
}

void	split_b(t_stacks s, int *min, int max)
{
	if (s.b->i_end < 10)
	{
		sort(s, min, max);
		return ;
	}
	next_sort(s, min);
	if (!range_in_tab(*s.b, *min, max))
	{
		int med = get_med(*s.b) + 1;
		
		if (s.b->i_end >= 0)
			split_b(s, &med, get_max(*s.b));
		push_b(s, min, max);
		return;
	}
	if (is_between(s.b->tab[0], *min, max))
		push(s.b, s.a);
	else
		rotate(s.b);
	split_b(s, min, max);
}

void	push_b(t_stacks s, int *min, int max)
{
	next_sort(s, min);
	if (s.b->i_end < 10)
	{
		sort(s, min, max);
		return ;
	}
	dual_swap(s);
	if (is_between(s.a->tab[0], *min, max))
		push(s.b, s.a);
	else
		split_b(s, min, max);
	push_b(s, min, max);
}

void	split_a(t_stacks s, int *min, int max)
{
	int 	med;

	if (!range_in_tab(*s.a, *min, max))
	{
		med = get_med(*s.b);
		split_b(s, &med, max);
		return ;
	}
	if (is_between(s.a->tab[0], *min, max))
		push(s.a, s.b);
	else
	{
		if (s.b->tab[0] < s.b->tab[s.b->i_end] && s.b->i_end > 0)
			rrotate(s.a, s.b);
		else
			rotate(s.a);
	}
	split_a(s, min, max);
}

void	algo_big(t_stacks s)
{
	int max;
	int min;

	max = s.a->i_end;
	min = 0;
	split_a(s, &min, get_med(*s.a));
	min = s.a->tab[s.a->i_end] + 1;
	split_a(s, &min, max);
}

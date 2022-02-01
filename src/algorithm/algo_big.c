/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/31 21:54:12 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(int nb, t_stacks s)
{
	ssize_t	i_nb;

	if (nb == -1)
		return ;
	i_nb = get_index(nb, *s.b);
	if (i_nb == -1)
		return ;
	if (i_nb < s.b->i_end / 2)
	{
		while (s.b->tab[0] != nb)
		{
			rotate(s.b);
			put_stack(s);
		}
	}
	else
	{
		while (s.b->tab[0] != nb)
			rev_rotate(s.b);
	}
	push(s.b, s.a);
}

void	next_sort(t_stacks s)
{
	if (s.a->tab[0] == *s.max_sort)
		rotate(s.a);
	else if (s.a->tab[1] == *s.max_sort)
	{
		swap(s.a);
		rotate(s.a);
	}
	else if (s.b->tab[0] == *s.max_sort)
	{
		push(s.b, s.a);
		rotate(s.a);
	}
	else
		return ;
	(*s.max_sort)++;
	next_sort(s);
}

bool	is_in_tab(int nb, t_stack s)
{
	while (s.i_end >= 0)
		if (s.tab[s.i_end--] == nb)
			return (true);
	return (false);
}

void	sort(t_stacks s, int max)
{
	next_sort(s);
	if (*s.max_sort >= max)
		return ;
	if (is_in_tab(*s.max_sort, *s.a))
		push(s.a, s.b);
	else
		push_a(*s.max_sort, s);
	sort(s, max);
}

bool	is_between(int nb, int min, int max)
{
	if (nb >= min && nb <= max)
		return (true);
	return (false);
}

bool	range_in_tab(t_stack s, int min, int max)
{
	while (s.i_end >= 0)
	{
		if (is_between(s.tab[s.i_end], min, max))
			return (true);
		s.i_end--;
	}
	return (false);
}

void	first_split(t_stacks s, int min, int max)
{
	if (!range_in_tab(*s.a, min, max))
		return ;
	if (is_between(s.a->tab[0], min, max))
		push(s.a, s.b);
	else
		rotate(s.a);
	first_split(s, min, max);
}

void	second_split(t_stacks s, int min, int max)
{
	if (!range_in_tab(*s.a, min, max))
		return ;
	// if (s.a->tab[0] == *s.max_sort)
	// {
	// 	rotate(s.a);
	// 	(*s.max_sort)++;
	// 	min--;
	// }
	if (is_between(s.a->tab[0], min, max))
		push(s.a, s.b);
	else
		rotate(s.a);
	second_split(s, min, max);
}

void	split_b(t_stacks s)
{
	int	med;
	int max;

	med = get_med(*s.b);
	max = get_max(*s.b);
	if (s.b->i_end < 10)
	{
		sort(s, max);
		return ;
	}
	while (range_in_tab(*s.b, med, max))
	{
		next_sort(s);
		if (is_between(s.b->tab[0], med, max))
			push(s.b, s.a);
		else
			rotate(s.b);
	}
	split_b(s);
}

void	algo_big(t_stacks s)
{
	int	med;
	int max;

	med = get_med(*s.a);
	max = get_max(*s.a);
	first_split(s, 0, med);
	split_b(s);
	sort(s, med);
	second_split(s, *s.max_sort + 1, max);
	// split_b(s);
	// sort(s, max);
	// split_b(s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:31:40 by tonted            #+#    #+#             */
/*   Updated: 2022/02/04 22:41:49 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	o_rotate_b(t_stacks s, int med)
{
	put_stack(s);
	if (s.b->tab[0] <= med && s.b->tab[0] < s.b->tab[1])
		rrotate(s.a, s.b);
	else
		rotate(s.a);
}

void	split_a(t_stacks s, int min, int max)
{
	if (!range_in_tab(*s.a, min, max))
		return ;
	if (is_between(s.a->tab[0], min, max))
		push(s.a, s.b);
	else
		o_rotate_b(s, (max - min) / 2);
	split_a(s, min, max);
	int med =  get_med(*s.a);
	while(s.a->tab[s.a->i_end] < med)
		rev_rotate(s.a);
	
}


void	opti_sort_to_a(t_stacks s)
{
	put_stack(s);
	if (s.a->tab[0] == *s.max_sort)
		;
	else if (s.b->i_end > 0 && s.b->tab[0] == *s.max_sort)
		push(s.b, s.a);
	else if (s.b->i_end > 0 && s.b->tab[0] == get_max(*s.b))
	{
		push(s.b, s.a);
	}
	else if (s.b->i_end > 0 && s.b->tab[s.b->i_end] == get_max(*s.b) && (s.b->tab[1] == *s.max_sort || s.b->tab[1] == get_max(*s.b) - 1))
	{
		rev_rotate(s.b);
		push(s.b, s.a);
	}
	else if (s.b->i_end > 0 && s.b->tab[1] == get_max(*s.b) && (s.b->tab[0] == *s.max_sort || s.b->tab[0] == get_max(*s.b) - 1))
	{
		if (s.a->tab[0] > s.a->tab[1] && s.a->tab[1] != 0)
			sswap(s.a, s.b);
		else
			swap(s.b);
		push(s.b, s.a);
	}
	else
		return ;
	if (s.a->tab[0] == *s.max_sort)
	{(*s.max_sort)++;
	if (s.b->tab[1] == get_max(*s.b) || s.b->tab[1] == (*s.max_sort))
		rrotate(s.a, s.b);
	else 
		rotate(s.a);}
	opti_sort_to_a(s);
}

int		sort_to_a(t_stacks s)
{
	if (s.b->i_end < 0)
		return (1);
	opti_sort_to_a(s);
	if (s.b->tab[0] == get_max(*s.b))
		push(s.b, s.a);
	else
		rotate(s.b);
	sort_to_a(s);
	return (1);
}

void	opti_split_b(t_stacks s, int min, int max)
{
	if (s.a->tab[0] == *s.max_sort)
		;
	else if (s.b->tab[0] == *s.max_sort)
		push(s.b, s.a);
	else
		return ;
	(*s.max_sort)++;
	if (!is_between(s.b->tab[0], min, max))
		rrotate(s.a, s.b);
	else
		rotate(s.a);
	opti_split_b(s, min, max);
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

void	sort_b(t_stacks s, int min);

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
		rotate(s.a);
		(*s.max_sort)++;
		min++;
	}
	else if (is_between(s.a->tab[0], min, max))
		push(s.a, s.b);
	push_to_b(s, min, max);
}


void	next_sort(t_stacks s)
{
	if (s.a->tab[0] == *s.max_sort)
		;
	else if (s.b->tab[0] == *s.max_sort)
		push(s.b, s.a);
	else
		return ;
	(*s.max_sort)++;
	rotate(s.a);
	next_sort(s);
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
	next_sort(s);
	push_to_b(s, *s.max_sort, max);
}

void	algo_big(t_stacks s)
{
	int	min;

	min = 0;
	split_a(s, min, get_med(*s.a));
	sort_b(s, min);
	push_to_b(s, *s.max_sort, get_max(*s.a));
}
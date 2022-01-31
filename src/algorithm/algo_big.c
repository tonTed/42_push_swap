/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/30 20:46:31 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(int nb, t_stacks s)
{
	ssize_t	i_nb;

	if (nb == -1)
		return ;
	i_nb = get_index(nb, *s.a);
	if (i_nb < s.a->i_end / 2)
		while (s.a->tab[0] != nb)
			rotate(s.a);
	else
		while (s.a->tab[0] != nb)
			rev_rotate(s.a);
	push(s.a, s.b);
}

void	push_a(int nb, t_stacks s)
{
	ssize_t	i_nb;

	if (nb == -1)
		return ;
	i_nb = get_index(nb, *s.b);
	if (i_nb < s.b->i_end / 2)
		while (s.b->tab[0] != nb)
			rotate(s.b);
	else
		while (s.b->tab[0] != nb)
			rev_rotate(s.b);
	push(s.b, s.a);
}

void	sort_to_a(t_stacks s)
{
	if (s.b->i_end == -1)
		return ;
	push_a(get_min(*s.b), s);
	if (s.a->tab[0] == s.a->tab[s.a->i_end] + 1 || s.a->tab[0] == 0)
		rotate(s.a);
	sort_to_a(s);
}

int		get_next(t_stack s, int min, int max)
{
	ssize_t	i;

	i = 0;
	while(i < s.i_end - i)
	{
		if (s.tab[i] >= min && s.tab[i] <= max)
			return (s.tab[i]);
		else if (s.tab[s.i_end - i] >= min && s.tab[s.i_end - i] <= max)
			return (s.tab[s.i_end - i]);
		i++;
	}
	return (-1);
}

void	split_to_a(t_stacks s, int min, int max)
{
	int	next;
	
	if (s.b->i_end < 12)
	{
		sort_to_a(s);
		return ;
	}
	next = get_next(*s.b, min, max);
	if (next == -1)
		split_to_a(s, get_med(*s.b), get_max(*s.b));
	push_a(next ,s);
	put_stack(s);
	split_to_a(s, min, max);
}

void	sort_a(t_stacks s, int min, int max)
{
	int	next;

	put_stack(s);
	next = s.a->tab[s.a->i_end] + 1;
	if (next > max)
		return ;
	if (s.a->tab[0] == next)
		rotate(s.a);
	else if (get_next(*s.a, next, next) == -1)
		push_a(next, s);
	else if (s.a->tab[1] == next)
	{
		if (s.b->i_end > 0 && s.b->tab[0] > s.b->tab[1])
			sswap(s.a, s.b);
		else
			swap(s.a);
	}
	else
		push(s.a, s.b);
	sort_a(s, min, max);
}

void	split_to_b(t_stacks s, int min, int max)
{
	int	next;
	
	next = get_next(*s.a, min, max);
	if (next == -1)
	{
		split_to_a(s, get_med(*s.b), get_max(*s.b));
		return ;
	}
	push_b(next ,s);
	split_to_b(s, min, max);
	sort_a(s, min, max);
}

void	algo_big(t_stacks s)
{
	int	med;

	put_stack(s);
	med = get_med(*s.a);
	// printf("med: %d\n",med);
	split_to_b(s, get_min(*s.a), med);
	// sort_a(s, get_min(*s.a), med);
	split_to_b(s, med + 1, get_max(*s.a));
	// sort_a(s, med + 1, get_max(*s.a));
	return ;
}

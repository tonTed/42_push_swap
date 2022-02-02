/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_old.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/31 19:32:21 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "push_swap.h"

void	sort_a(t_stacks s, int min, int max);
void	split_to_a(t_stacks s, int min, int max);

void	next_sort(t_stacks s, int *min)
{
	if (s.a->tab[0] == *s.max_sort)
	{
		(*min)--;
		rotate(s.a);
		(*s.max_sort)++;
		next_sort(s, min);
	}
}

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
		if (s.tab[i] >= min && s.tab[i] <= max && s.tab[i])
			return (s.tab[i]);
		else if (s.tab[s.i_end - i] >= min && s.tab[s.i_end - i] <= max)
			return (s.tab[s.i_end - i]);
		i++;
	}
	return (-1);
}

int		amount_in_s(t_stack s, int min, int max)
{
	int	count;

	count = 0;
	while (s.i_end >=0)
	{
		if (s.tab[s.i_end] >= min && s.tab[s.i_end] <= max)
			count++;
		s.i_end--;
	}
	return (count);
}

void	split_to_b2(t_stacks s, int min, int max)
{
	int	next;
	int med;

	next_sort(s, &min);
	if (max - min < 60)
	{
		sort_a(s, min, max);
		return;
	}
	next = get_next(*s.a, min, max);
	if (next == -1)
	{
		med = (max - min) / 2 + min;
		split_to_a(s, min, med);
		split_to_a(s, med + 1, min);
		return ;
	}
	split_to_b2(s, min, max);
}

void	split_to_a(t_stacks s, int min, int max)
{
	int	next;
	int	med;
	
	next = get_next(*s.b, min, max);
	next_sort(s, &min);
	if (max - min < 60)
	{
		sort_a(s, min, max);
		return;
	}
	if (next == -1)
	{
		med = (max - min) / 2 + min;
		split_to_b2(s, min, med);
		split_to_b2(s, med + 1, max);
		return ;
	}
	push_a(next ,s);
	put_stack(s);
	split_to_a(s, min, max);
}

void	sort_a(t_stacks s, int min, int max)
{
	int	next;

	put_stack(s);
	next = *s.max_sort;
	if (next > max)
		return ;
	if (s.a->tab[0] == next)
	{
		rotate(s.a);
		(*s.max_sort)++;
	}
	else if (s.a->tab[1] == next)
	{
		if (s.b->i_end > 0 && s.b->tab[0] > s.b->tab[1])
			sswap(s.a, s.b);
		else
			swap(s.a);
	}
	else if (get_index(next, *s.a) != -1)
		push(s.a, s.b);
	else
		push_a(next, s);
	sort_a(s, min, max);
}

void	split_to_b(t_stacks s, int min, int max)
{
	int	next;
	
	// if (*s.max_sort != 0)
	// 	next_sort(s, &min);
	next = get_next(*s.a, min, max);
	if (next == -1)
		return ;
	push_b(next ,s);
	split_to_b(s, min, max);
}

void	algo_big(t_stacks s)
{
	int	tiers1;
	int	tiers2;
	int	tiers3;
	
	tiers1 = s.a->i_end / 2;
	tiers2 = tiers1 * 2;
	tiers3 = s.a->i_end + 1;

	put_stack(s);
	// split_to_b(s, 20, 40);
	// split_to_b(s, 0, 19);
	// split_to_a(s, 0, 9);
	// split_to_a(s, 10, 19);
	// split_to_a(s, 20, 30);
	// split_to_a(s, 31, 40);
	// split_to_b(s, 41, 59);
	// split_to_a(s, 41, 50);
	// sort_a(s, 51, 59);
	
	// split_to_b(s, 33, 66);		
	// split_to_b(s, 0, 32);		
	// split_to_a(s, 0, 16);		
	// split_to_a(s, 17, 32);		
	// split_to_a(s, 33, 49);		
	// split_to_a(s, 50, 66);		
	// split_to_b(s, 67, 99);		
	// split_to_a(s, 67, 82);		
	// sort_a(s, 82, 99);			
	
	split_to_b(s, 165, 330);		
	split_to_b(s, 0, 164);		
	split_to_a(s, 0, 82);		
	split_to_a(s, 83, 164);		
	split_to_a(s, 165, 240);		
	split_to_a(s, 249, 300);		
	split_to_b(s, 301, 499);		
	split_to_a(s, 301, 410);		
	sort_a(s, 410, 499);			
	return ;
}

*/
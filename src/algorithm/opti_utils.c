/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:08:54 by tonted            #+#    #+#             */
/*   Updated: 2022/02/05 09:53:40 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_sswap(t_stacks s)
{
	if (s.a->tab[0] > s.a->tab[1] && s.a->tab[1] != 0)
		sswap(s.a, s.b);
	else
		swap(s.b);
	push(s.b, s.a);
}

void	o_rotate_b(t_stacks s, int med)
{
	put_stack(s);
	if (s.b->tab[0] <= med && s.b->tab[0] < s.b->tab[1])
		rrotate(s.a, s.b);
	else
		rotate(s.a);
}

ssize_t	next_to_push_to_a(t_stacks s)
{
	int i;
	int i_end;
	int	max;

	i = 0;
	i_end = s.b->i_end;
	max = get_max(*s.b);
	while (i < i_end - i)
	{
		if (s.b->tab[i] == *s.max_sort || s.b->tab[i] == max)
			return (i);
		if (s.b->tab[i_end - i] == *s.max_sort 
			|| s.b->tab[i_end - i] == max)
			return (i_end - i);
		i++;
	}
	return (-1);
}

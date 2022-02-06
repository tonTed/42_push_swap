/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:31:40 by tonted            #+#    #+#             */
/*   Updated: 2022/02/05 21:43:54 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_a(t_stacks s, int min, int max)
{
	int	med;

	if (!range_in_tab(*s.a, min, max))
		return ;
	if (is_between(s.a->tab[0], min, max))
		push(s.a, s.b);
	else
		o_rotate_b(s, (max - min) / 2);
	split_a(s, min, max);
	med = get_med(*s.a);
	while (s.a->tab[s.a->i_end] < med)
		rev_rotate(s.a);
	while (s.a->tab[0] >= med)
		rotate(s.a);
}

void	algo_big(t_stacks s)
{
	int	min;

	min = 0;
	split_a(s, min, get_med(*s.a));
	sort_b(s, min);
	push_to_b(s, *s.max_sort, get_max(*s.a));
}

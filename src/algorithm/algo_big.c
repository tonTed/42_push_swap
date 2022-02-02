/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:31:40 by tonted            #+#    #+#             */
/*   Updated: 2022/02/02 18:47:53 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	o_rotate_b(t_stacks s)
{
	if (s.b->tab[0] < s.b->tab[1])
		rrotate(s.a, s.b);
	else
		rotate(s.a);
}

int	split_a(t_stacks s, int *min, int max)
{
	if (!range_in_tab(*s.a, *min, max))
		return (max);
	if (is_between(s.a->tab[0], *min, max))
		push(s.a, s.b);
	else
		o_rotate_b(s);
	split_a(s, min, max);
	return (max);
}

void	algo_big(t_stacks s)
{
	int	min;
	int	med;

	min = 0;
	med = split_a(s, &min, get_med(*s.a));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/31 19:59:50 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_between(int nb, int min, int max)
{
	if (nb >= min && nb <= max)
		return (true);
	return (false);
}

bool	is_in_tab(t_stack s, int min, int max)
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
	if (!is_in_tab(*s.a, min, max))
		return ;
	if (is_between(s.a->tab[0], min, max))
		push(s.a, s.b);
	else
		rotate(s.a);
	first_split(s, min, max);
}

void	algo_big(t_stacks s)
{
	int	med;

	med = get_med(*s.a);
	first_split(s, 0, med);
	
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:40:49 by tonted            #+#    #+#             */
/*   Updated: 2022/02/01 11:41:59 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_in_tab(int nb, t_stack s)
{
	while (s.i_end >= 0)
		if (s.tab[s.i_end--] == nb)
			return (true);
	return (false);
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

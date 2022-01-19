/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:59:51 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/19 16:39:15 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dual_move(t_stack sa, t_stack sb)
{
	bool	continue_;

	continue_ = true;
	while (continue_)
	{
		continue_ = false;
		if (is_firsts_big_lasts(sa, sb))
			continue_ = true;
		if (is_firsts_big_second(sa, sb))
			continue_ = true;
		if (is_firsts_small_lasts(sa, sb))
			continue_ = true;
	}
}

void	algorithm(t_stack sa, t_stack sb)
{
	while ((*sb.last_i != -1 || !(ft_issorted(sa.tab.tab, sa.tab.size))))
	{
		dual_move(sa, sb);
		swap(sa);
	}
}

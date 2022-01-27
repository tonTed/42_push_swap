/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/26 21:50:07 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_big(t_stack sa, t_stack sb)
{
	ssize_t	med;
	int		fu;

	med = get_med(sa);
	fu = (sa.tab.size - *sa.last_i - 1);
	if (*sa.last_i == 2)
	{
		algo_3(sa);
		return ;
	}
	while (*sa.last_i > med && *sa.last_i > 2)
	{
		if (to_swap(sa, sb))
			continue ;
		else if (sa.tab.tab[0] <= (med + fu))
			push(sa, sb);
		else
			rotate(sa);
		put_stack(sa, sb);
	}
	algo_big(sa, sb);
}

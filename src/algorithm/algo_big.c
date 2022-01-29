/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/29 11:59:25 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

input : 2 5 4 1 8 0 6 3 9 7
smaller = 0
i_last = 9 
index to push -> (i_last) / 2 = 4
number to push > smaller + index to push -> 0 + 5  - 1 = 4

input : 2 5 4 1 8 0 6 3 7
smaller = 0
i_last = 8 
index to push -> (i_last) / 2 = 4
number to push > smaller + index to push -> 0 + 4 = 4

sb : 2 5 4 1 8 0 6 3 9 7

*/

void	first_push(t_stack src, t_stack dst, t_stacks stacks)
{
	int		med;
	
	med = get_med(src);
	while (is_number(src, med) != -1)
	{
		to_swap(stacks);
		push_next_half(src, dst, med);
	}
}


void	sort_b(t_stacks stacks)
{
	int		med;
	
	med = get_med(*stacks.sb);
	if (*stacks.sb->last_i < 10)
	{
		while (*stacks.sb->last_i >= 0)
		{
			push_next_bigger(*stacks.sb, *stacks.sa);
			rotate(*stacks.sa);
		}
		return ;
	}
	else
		first_push(*stacks.sb, *stacks.sa, stacks);
	sort_b(stacks);
}

void	algo_big(t_stacks stacks)
{
	first_push(*stacks.sa, *stacks.sb, stacks);
	sort_b(stacks);
}
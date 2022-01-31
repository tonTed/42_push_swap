/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/29 21:49:13 by tonted           ###   ########.fr       */
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

int	split_2(t_stack src, t_stack dst)
{
	int		med;

	med = get_med(src);
	while (is_numbers(src, med) != -1)
		push_next(src, dst, med);
	return (med);
}

void	sort_a(t_stacks stacks, int med)
{
	if (med <= stacks.sa->tab.tab[*stacks.sa->last_i])
		return ;
	if (is_number(*stacks.sa, stacks.sa->tab.tab[*stacks.sa->last_i] + 1))
	{
		if (stacks.sa->tab.tab[0] == stacks.sa->tab.tab[*stacks.sa->last_i] + 1)
			rotate(*stacks.sa);
		else if (stacks.sa->tab.tab[0] > stacks.sa->tab.tab[1])
			swap(*stacks.sa);
		else
			push(*stacks.sa, *stacks.sb);
	}
	else if (*stacks.sb->last_i != -1)
		sort_to_a(*stacks.sb, *stacks.sa);
	sort_a(stacks, med);
}

int	sort_b(t_stacks stacks)
{
	int		med;

	med = get_med(*stacks.sb);
	if (*stacks.sb->last_i < 10)
	{
		while (*stacks.sb->last_i >= 0)
		{
			sort_to_a(*stacks.sb, *stacks.sa);
			rotate(*stacks.sa);
		}
		return (0);
	}
	else
		split_2(*stacks.sb, *stacks.sa);
	sort_b(stacks);
	return (med);
}

void	second_wave(t_stacks stacks)
{
	size_t	i;

	i = 0;
	if (stacks.sa->tab.tab[i] == 0)
		return ;
	if (stacks.sa->tab.tab[0] - 1 == stacks.sa->tab.tab[i])
		rotate(*stacks.sa);
	else
		push(*stacks.sa, *stacks.sb);
	second_wave(stacks);
}

void	algo_big(t_stacks stacks)
{
	int	med;

	med = split_2(*stacks.sa, *stacks.sb);
	sort_b(stacks);
	sort_a(stacks, med);
	second_wave(stacks);
	sort_b(stacks);
	sort_a(stacks, *stacks.sa->last_i);
}

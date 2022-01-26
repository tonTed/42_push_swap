/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:15:07 by tonted            #+#    #+#             */
/*   Updated: 2022/01/25 20:43:19 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"\

// check if is the bigger in the tab
static bool	is_bigger_tab(t_stack stack, int num)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = *stack.last_i + 1;
	while (i < len)
		if (stack.tab.tab[i++] > num)
			return (false);
	return (true);
}

// check if is the bigger in the tab
static bool	is_smaller_tab(t_stack stack, int num)
{
	size_t	i;
	size_t	len;

	len = *stack.last_i + 1;
	i = 0;
	while (i < len)
		if (stack.tab.tab[i++] < num)
			return (false);
	return (true);
}

static bool	sort_3(t_stack sa)
{
	if (is_bigger_tab(sa, sa.tab.tab[0]))
		rotate(sa);
	else if (is_smaller_tab(sa, sa.tab.tab[*sa.last_i]))
		rev_rotate(sa);
	else if (is_smaller_tab(sa, sa.tab.tab[1])
		|| is_bigger_tab(sa, sa.tab.tab[1]))
		swap(sa);
	else
		return (false);
	return (true);
}

void	algo_3(t_stack sa)
{
	sort_3(sa);
	if (ft_issorted(sa.tab.tab, *sa.last_i + 1))
		return ;
	else
		algo_3(sa);
}

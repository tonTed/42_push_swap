/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:15:29 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/29 11:58:16 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_push(t_stack src, t_stack dst, int to_push)
{
	while (to_push != src.tab.tab[0])
		rotate(src);
	push(src, dst);
}

void	rev_rotate_push(t_stack src, t_stack dst, int to_push)
{
	while (to_push != src.tab.tab[0])
		rev_rotate(src);
	push(src, dst);
}

void	push_next_bigger(t_stack src, t_stack dst)
{
	ssize_t	i_bigger;

	i_bigger = where_is_bigger(src);
	if (i_bigger < (*src.last_i) / 2)
	{
		if (src.name == 'a')
			rotate_push(src, dst, src.tab.tab[i_bigger]);
		else
			rev_rotate_push(src, dst, src.tab.tab[i_bigger]);
	}
	else
	{
		if (src.name == 'a')
			rev_rotate_push(src, dst, src.tab.tab[i_bigger]);
		else
			rotate_push(src, dst, src.tab.tab[i_bigger]);
	}
}

void	push_next_half(t_stack src, t_stack dst, int med)
{
	ssize_t	i_next;

	i_next = is_number(src, med);
	if (i_next == 0)
		push(src, dst);
	else if (i_next < (*src.last_i) / 2)
		rotate_push(src, dst, src.tab.tab[i_next]);
	else
		rev_rotate_push(src, dst, src.tab.tab[i_next]);
}
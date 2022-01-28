/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:15:29 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/28 10:53:51 by tblanco          ###   ########.fr       */
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


void	push_next(t_stack src, t_stack dst)
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
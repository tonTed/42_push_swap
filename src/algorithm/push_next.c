/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:15:29 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/29 21:44:48 by tonted           ###   ########.fr       */
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

size_t	where_is_bigger(t_stack stack)
{
	ssize_t	i;
	int		max;
	size_t	ret;

	i = 0;
	ret = 0;
	max = stack.tab.tab[i];
	while (i <= *stack.last_i)
	{
		if (stack.tab.tab[i] < max)
		{
			max = stack.tab.tab[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

void	sort_to_a(t_stack src, t_stack dst)
{
	ssize_t	i_next;

	i_next = where_is_bigger(src);
	if (*src.last_i == 0)
		push(src, dst);
	else if (i_next < (*src.last_i) / 2)
		rotate_push(src, dst, src.tab.tab[i_next]);
	else
		rev_rotate_push(src, dst, src.tab.tab[i_next]);
}

void	push_next(t_stack src, t_stack dst, int med)
{
	ssize_t	i_next;

	i_next = is_numbers(src, med);
	if (i_next == 0)
		push(src, dst);
	else if (i_next < (*src.last_i) / 2)
		rotate_push(src, dst, src.tab.tab[i_next]);
	else
		rev_rotate_push(src, dst, src.tab.tab[i_next]);
}

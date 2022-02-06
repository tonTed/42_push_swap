/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:00:23 by tonted            #+#    #+#             */
/*   Updated: 2022/02/05 20:06:06 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	if ((*src).i_end >= 0)
	{
		(*dst).i_end += 1;
		move_down(dst);
		(*dst).tab[0] = (*src).tab[0];
		(*src).i_end -= 1;
		move_up(src);
		print_op("p", (*dst).name);
	}
}

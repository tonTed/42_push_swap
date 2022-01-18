/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:00:23 by tonted            #+#    #+#             */
/*   Updated: 2022/01/18 15:22:37 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack src, t_stack dst)
{
	if (*src.last_i)
	{
		(*dst.last_i)++;
		move_down(dst);
		dst.tab.tab[0] = src.tab.tab[0];
		(*src.last_i)--;
		move_up(src);
		print_op("p", dst.name);
	}
}

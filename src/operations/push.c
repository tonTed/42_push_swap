/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:00:23 by tonted            #+#    #+#             */
/*   Updated: 2022/01/26 17:50:23 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack src, t_stack dst)
{
	if (*src.last_i >= 0)
	{
		*dst.last_i += 1;
		move_down(dst);
		dst.tab.tab[0] = src.tab.tab[0];
		*src.last_i -= 1;
		move_up(src);
		print_op("p", dst.name);
	}
}

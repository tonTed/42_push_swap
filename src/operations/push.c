/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:00:23 by tonted            #+#    #+#             */
/*   Updated: 2021/12/27 23:12:22 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack src, t_stack dst)
{
	if (*src.last_i)
	{
		// ft_putstr_fd(REDHB ">>> DEBUG <<<\n" RESET, 1);
		(*dst.last_i)++;
		move_down(dst);
		dst.tab.tab[0] = src.tab.tab[0];
		(*src.last_i)--;
		move_up(src);
		print_op("p", dst.name);
	}
}

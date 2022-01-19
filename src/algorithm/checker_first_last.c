/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_first_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:42:37 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/19 16:23:56 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_first_bigger_last(int *tab, ssize_t len)
{
	return (tab[0] > tab[len - 1]);
}

bool	is_firsts_big_lasts(t_stack sa, t_stack sb)
{
	if (is_first_bigger_last(sa.tab.tab, *sa.last_i + 1)
		&& !(is_first_bigger_last(sb.tab.tab, *sb.last_i + 1)))
	{
		rrotate(sa, sb);
		return (true);
	}
	return (false);
}

bool	is_firsts_small_lasts(t_stack sa, t_stack sb)
{
	if (!(is_first_bigger_last(sa.tab.tab, *sa.last_i + 1))
		&& (is_first_bigger_last(sb.tab.tab, *sb.last_i + 1)))
	{
		rev_rrotate(sa, sb);
		return (true);
	}
	return (false);
}

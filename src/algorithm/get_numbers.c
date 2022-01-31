/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:48:01 by tonted            #+#    #+#             */
/*   Updated: 2022/01/30 18:14:53 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_min(t_stack s)
{
	int	min;

	min = s.tab[s.i_end];
	while (s.i_end >= 0)
	{
		if (s.tab[s.i_end] < min)
			min = s.tab[s.i_end];
		s.i_end--;
	}
	return (min);
}

int		get_max(t_stack s)
{
	int	max;

	max = s.tab[s.i_end];
	while (s.i_end >= 0)
	{
		if (s.tab[s.i_end] > max)
			max = s.tab[s.i_end];
		s.i_end--;
	}
	return (max);
}

int		get_med(t_stack s)
{
	return((get_max(s) - get_min(s)) / 2);
}

ssize_t	get_index(int nb, t_stack s)
{
	while (s.i_end != -1)
	{
		if (s.tab[s.i_end] == nb)
			return (s.i_end);
		s.i_end--;
	}
	return (-1);
}

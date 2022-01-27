/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:50:10 by tonted            #+#    #+#             */
/*   Updated: 2022/01/27 12:33:06 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_med(t_stack stack)
{
	return (*stack.last_i / 2);
}

size_t	where_is_bigger(t_stack stack)
{
	ssize_t	i;
	int		max;
	size_t	ret;

	i = 0;
	ret = 0;
	max = stack.tab.tab[i];
	while (i < *stack.last_i - 1)
	{
		if (stack.tab.tab[++i] > max)
		{
			max = stack.tab.tab[i];
			ret = i;
		}
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:50:10 by tonted            #+#    #+#             */
/*   Updated: 2022/01/28 11:49:50 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_smaller(t_stack stack)
{
	size_t	smaller;
	size_t	i;

	i = 0;
	smaller = stack.tab.tab[i];
	while (i <= *stack.last_i)
	{
		if (stack.tab.tab[i] < smaller)
			smaller = stack.tab.tab[i];
		i++;
	}
	return (smaller);
}

size_t	get_med(t_stack stack)
{
	
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
		if (stack.tab.tab[i] > max)
		{
			max = stack.tab.tab[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

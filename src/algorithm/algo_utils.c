/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:50:10 by tonted            #+#    #+#             */
/*   Updated: 2022/01/29 11:09:03 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_smaller(t_stack stack)
{
	int		smaller;
	ssize_t	i;

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

int		get_bigger(t_stack stack)
{
	int		smaller;
	ssize_t	i;

	i = 0;
	smaller = stack.tab.tab[i];
	while (i <= *stack.last_i)
	{
		if (stack.tab.tab[i] > smaller)
			smaller = stack.tab.tab[i];
		i++;
	}
	return (smaller);
}

int		get_med(t_stack stack)
{
	// printf(" >>> WTF? <<<<\n");
	if (stack.name == 'a')
	{
		if (*stack.last_i % 2 == 0)
			return (get_smaller(stack) + ((size_t)*stack.last_i / 2) - 1);
		return (get_smaller(stack) + ((size_t)*stack.last_i / 2));
	}
	else
	{
		if (*stack.last_i % 2 == 0)
			return (get_bigger(stack) - ((size_t)*stack.last_i / 2) - 1);
		return (get_bigger(stack) - ((size_t)*stack.last_i / 2));
	}
}

ssize_t	is_number(t_stack stack, int nb)
{
	ssize_t	i;

	i = 0;
	if (stack.name == 'a')
	{
		while (i < *stack.last_i - i)
		{
			if (nb >= stack.tab.tab[i])
				return (i);
			else if (nb >= stack.tab.tab[*stack.last_i - i])
				return (*stack.last_i - i);
			i++;
		}
	}
	else if (stack.name == 'b')
	{
		while (i < *stack.last_i - i)
		{
			if (nb <= stack.tab.tab[i])
				return (i);
			else if (nb <= stack.tab.tab[*stack.last_i - i])
				return (*stack.last_i - i);
			i++;
		}
	}
	return (-1);
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

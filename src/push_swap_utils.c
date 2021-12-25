/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:43:27 by tonted            #+#    #+#             */
/*   Updated: 2021/12/24 21:18:18 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	isnumberzero(char *str)
{
	while (ft_iswhitespace(*str))
		str++;
	if (ft_issign(*str))
		str++;
	while (*str == '0')
		str++;
	if (*str)
		return (false);
	return (true);
}

bool	isduplicatenumbers(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

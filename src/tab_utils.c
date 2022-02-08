/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:59:00 by tonted            #+#    #+#             */
/*   Updated: 2022/02/08 09:48:47 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tab_zero(size_t len)
{
	int		*tab;
	size_t	i;

	i = 0;
	tab = (int *)malloc(sizeof(size_t) * len);
	while (i < len)
		tab[i++] = 0;
	return (tab);
}

int	*tab_convert(int *tab, size_t len)
{
	size_t	i_tab;
	size_t	i_new;
	size_t	count;
	int		*tabnew;

	i_new = 0;
	tabnew = (int *)malloc(sizeof(int) * (len + 1));
	while (i_new < len)
	{
		i_tab = 0;
		count = 0;
		while (i_tab < len)
			if (tab[i_new] > tab[i_tab++])
				count++;
		tabnew[i_new++] = count;
	}
	free(tab);
	return (tabnew);
}

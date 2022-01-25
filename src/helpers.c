/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:59:00 by tonted            #+#    #+#             */
/*   Updated: 2022/01/24 12:44:48 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*tab_zero(size_t len)
{
	int		*tab;
	size_t	i;

	i = 0;
	tab = (int *)malloc(sizeof(size_t) * len);
	while (i < len)
		tab[i++] = 0;
	return (tab);
}

// void	tab_convert(int *tab, size_t len)
// {
// 	size_t	*tabnew;
// 	size_t	*indexing;
// 	size_t	i_new;
// 	size_t	i_big;
// 	size_t	i;

// 	i_new = 0;
// 	i_big = 0;
// 	tabnew = (int *)malloc(sizeof(size_t) * len);
// 	indexing = tab_zero(len);
// 	while (i_new < len)
// 	{
// 		i = 0;
// 		while (i < len)
// 		{
// 			if (tab[i] > tab[i_big])
// 				i_big = i;
// 			i++;
// 		}
// 		i_new++;
// 	}
// }
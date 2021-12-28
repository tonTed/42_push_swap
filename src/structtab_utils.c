/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structtab_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:48:48 by tonted            #+#    #+#             */
/*   Updated: 2021/12/27 19:03:09 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tabint	create_tabint(char **tabstr)
{
	t_tabint	tab;
	size_t		i;

	tab.size = ft_strtablen(tabstr);
	tab.tab = (int *)malloc(sizeof(int) * tab.size);
	i = 0;
	while (i < tab.size)
	{
		tab.tab[i] = ft_atoi(tabstr[i]);
		if (tab.tab[i] == 0 && isnumberzero(tabstr[i]) == false)
			freeexit(&tabstr, &tab.tab, "Error\n");
		i++;
	}
	if (ft_isduplicates(tab.tab, tab.size))
		freeexit(&tabstr, &tab.tab, "Error\n");
	if (ft_issorted(tab.tab, tab.size))
		freeexit(&tabstr, &tab.tab, "");
	ft_freetabstr(&tabstr);
	return (tab);
}

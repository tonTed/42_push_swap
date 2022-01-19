/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:48:48 by tonted            #+#    #+#             */
/*   Updated: 2022/01/18 15:21:59 by tonted           ###   ########.fr       */
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

char	**create_tabstr(char **argv, int argc)
{
	char	**tab;
	int		i;

	if (argc < 2)
		return (NULL);
	else if (argc == 2)
		tab = ft_split(argv[1], SPACE);
	else
	{
		tab = (char **)malloc(sizeof(char *) * argc);
		i = 0;
		while (i < (argc - 1))
		{
			tab[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		tab[i] = NULL;
	}
	if (!ft_isnumberstab(tab))
		freeexit(&tab, NULL, "Error\n");
	return (tab);
}

t_stack	create_stack(t_tabint tab, bool empty, char name)
{
	t_stack		stack;
	t_tabint	tabint;

	stack.last_i = malloc(sizeof(size_t));
	stack.name = name;
	if (empty)
	{
		tabint.size = tab.size;
		tabint.tab = (int *)malloc(sizeof(tabint.size));
		stack.tab = tabint;
		*stack.last_i = -1;
	}
	else
	{
		stack.tab = tab;
		*stack.last_i = tab.size - 1;
		ft_reversetab(&tab.tab, tab.size);
	}
	return (stack);
}
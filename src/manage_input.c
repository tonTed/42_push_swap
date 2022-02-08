/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:48:48 by tonted            #+#    #+#             */
/*   Updated: 2022/02/08 09:48:24 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	create_stack(int **tab, size_t len)
{
	t_stacks	s;

	s.a = (t_stack *)malloc(sizeof(t_stack));
	s.b = (t_stack *)malloc(sizeof(t_stack));
	s.max_sort = (int *)malloc(sizeof(int));
	*s.max_sort = 0;
	s.a->i_end = (ssize_t)(len - 1);
	s.a->name = 'a';
	s.a->tab = *tab;
	s.b->i_end = -1;
	s.b->name = 'b';
	s.b->tab = (int *)malloc(sizeof(int) * (len + 1));
	ft_memset(s.b->tab, 0, len);
	return (s);
}

static t_stacks	create_tabint(char **tabstr)
{
	int		*tab;
	size_t	len;
	size_t	i;

	len = ft_strtablen(tabstr);
	tab = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		tab[i] = ft_atoi(tabstr[i]);
		if (tab[i] == 0 && isnumberzero(tabstr[i]) == false)
			freeexit(&tabstr, &tab, "Error\n");
		i++;
	}
	if (ft_isduplicates(tab, len))
		freeexit(&tabstr, &tab, "Error\n");
	ft_freetabstr(&tabstr);
	tab = tab_convert(tab, len);
	return (create_stack(&tab, len));
}

static char	**create_tabstr(char **argv, int argc)
{
	char	**tab;
	int		i;

	if (argc < 2)
		exit(EXIT_FAILURE);
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
	if (!tab)
		exit(EXIT_FAILURE);
	return (tab);
}

t_stacks	create_stacks(char **argv, int argc)
{
	char	**tabstr;

	tabstr = create_tabstr(argv, argc);
	return (create_tabint(tabstr));
}

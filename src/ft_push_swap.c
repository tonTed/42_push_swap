/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2021/12/24 21:16:46 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeexit(char ***tabstr, int **tabint)
{
	if (tabstr)
		ft_freetabstr(tabstr);
	if (tabint)
		ft_freetabint(tabint);
	ft_errorendl_fd(STDERR_FILENO);
	exit(EXIT_FAILURE);
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
		freeexit(&tab, NULL);
	return (tab);
}

int	*create_tabint(char **tabstr)
{
	int		*tabint;
	int		lentab;
	int		i;

	lentab = ft_strtablen(tabstr);
	tabint = (int *)malloc(sizeof(int) * lentab);
	i = 0;
	while (i < lentab)
	{
		tabint[i] = ft_atoi(tabstr[i]);
		if (tabint[i] == 0 && isnumberzero(tabstr[i]) == false)
			freeexit(&tabstr, &tabint);
		i++;
	}
	if (isduplicatenumbers(tabint, lentab))
		freeexit(&tabstr, &tabint);
	ft_freetabstr(&tabstr);
	return (tabint);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		*tabint;

	tab = create_tabstr(argv, argc);
	if (!tab)
		return (EXIT_FAILURE);
	tabint = create_tabint(tab);
	free(tabint);
	return (EXIT_SUCCESS);
}

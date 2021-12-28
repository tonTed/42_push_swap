/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2021/12/27 19:06:32 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	char		**tab;
	t_tabint	tabint;

	tab = create_tabstr(argv, argc);
	if (!tab)
		return (EXIT_FAILURE);
	tabint = create_tabint(tab);
	free(tabint.tab);
	return (EXIT_SUCCESS);
}

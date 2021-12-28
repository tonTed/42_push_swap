/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2021/12/28 12:42:23 by tonted           ###   ########.fr       */
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

t_stack	create_stack(t_tabint tab, bool empty, char name)
{
	t_stack	stack;

	stack.last_i = malloc(sizeof(size_t));
	stack.name = name;
	if (empty)
	{
		stack.tab.tab = (int *)malloc(sizeof(int) * tab.size);
		*stack.last_i = 0;
	}
	else
	{
		stack.tab = tab;
		*stack.last_i = tab.size - 1;
		ft_reversetab(&tab.tab, tab.size);
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	char		**tab;
	t_tabint	tabint;
	t_stack		stack_a;
	t_stack		stack_b;

	tab = create_tabstr(argv, argc);
	if (!tab)
		return (EXIT_FAILURE);
	tabint = create_tabint(tab);
	stack_a = create_stack(tabint, false, 'a');
	stack_b = create_stack(tabint, true, 'b');

	// TODO improve free items
	free(tabint.tab);
	free(stack_a.last_i);
	free(stack_b.last_i);
	free(stack_b.tab.tab);
	return (EXIT_SUCCESS);
}

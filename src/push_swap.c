/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/18 15:10:38 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(stack_a.tab.tab);
	free(stack_a.last_i);
	free(stack_b.tab.tab);
	free(stack_b.last_i);

	return (EXIT_SUCCESS);
}

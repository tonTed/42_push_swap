/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/24 13:26:06 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_algo(t_stack sa, t_stack sb)
{
	(void)sb;
	if (*sa.last_i == 2)
		algo_3(sa);
	else if (*sa.last_i <= 5)
		algo_5(sa, sb);
}

int	main(int argc, char **argv)
{
	t_tabint	tabint;
	t_stack		sa;
	t_stack		sb;

	tabint = create_tab(argv, argc);
	sa = create_stack(tabint, false, 'a');
	sb = create_stack(tabint, true, 'b');

	put_stack(sa, sb);
	manage_algo(sa,sb);
	// TODO improve free items
	free(sa.tab.tab);
	free(sa.last_i);
	free(sb.tab.tab);
	free(sb.last_i);

	return (EXIT_SUCCESS);
}

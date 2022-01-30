/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/29 21:45:54 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_algo(t_stacks stacks)
{
	if (*stacks.sa->last_i == 1)
		swap(*stacks.sa);
	else if (*stacks.sa->last_i == 2)
		algo_3(*stacks.sa);
	else if (*stacks.sa->last_i < 5)
		algo_5(stacks);
	else
		algo_big(stacks);
}

int	main(int argc, char **argv)
{
	t_tabint	tabint;
	t_stack		sa;
	t_stack		sb;
	t_stacks	stacks;

	tabint = create_tab(argv, argc);
	sa = create_stack(tabint, false, 'a');
	sb = create_stack(tabint, true, 'b');
	stacks = create_stacks(&sa, &sb);
	manage_algo(stacks);
	freestack(stacks);
	return (EXIT_SUCCESS);
}

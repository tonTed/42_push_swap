/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/27 16:55:35 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_algo(t_stack sa, t_stack sb)
{
	(void)sb;
	if (*sa.last_i == 1)
		swap(sa);
	else if (*sa.last_i == 2)
		algo_3(sa);
	else if (*sa.last_i < 5)
		algo_5(sa, sb);
	else
		algo_big(sa, sb);
}

int	main(int argc, char **argv)
{
	t_tabint	tabint;
	t_stack		sa;
	t_stack		sb;

	printf("['%s']\n", argv[1]);
	tabint = create_tab(argv, argc);
	sa = create_stack(tabint, false, 'a');
	sb = create_stack(tabint, true, 'b');
	// sleep(5);
	// put_stack(sa, sb);
	manage_algo(sa, sb);
	// put_stack(sa, sb);
	freestack(sa, sb);
	return (EXIT_SUCCESS);
}

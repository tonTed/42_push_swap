/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/19 12:04:01 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_tabint	tabint;
	t_stack		stack_a;
	t_stack		stack_b;

	tabint = create_tab(argv, argc);
	stack_a = create_stack(tabint, false, 'a');
	stack_b = create_stack(tabint, true, 'b');

	ft_puttabint_fd(stack_a.tab.tab, *stack_a.last_i + 1, 1);
	ft_puttabint_fd(stack_b.tab.tab, *stack_b.last_i + 1, 1);
	push(stack_a, stack_b);
	ft_puttabint_fd(stack_a.tab.tab, *stack_a.last_i + 1, 1);
	ft_puttabint_fd(stack_b.tab.tab, *stack_b.last_i + 1, 1);
	push(stack_a, stack_b);
	ft_puttabint_fd(stack_a.tab.tab, *stack_a.last_i + 1, 1);
	ft_puttabint_fd(stack_b.tab.tab, *stack_b.last_i + 1, 1);
	push(stack_a, stack_b);
	ft_puttabint_fd(stack_a.tab.tab, *stack_a.last_i + 1, 1);
	ft_puttabint_fd(stack_b.tab.tab, *stack_b.last_i + 1, 1);
	push(stack_a, stack_b);
	ft_puttabint_fd(stack_a.tab.tab, *stack_a.last_i + 1, 1);
	ft_puttabint_fd(stack_b.tab.tab, *stack_b.last_i + 1, 1);
	

	// TODO improve free items
	free(stack_a.tab.tab);
	free(stack_a.last_i);
	free(stack_b.tab.tab);
	free(stack_b.last_i);

	return (EXIT_SUCCESS);
}

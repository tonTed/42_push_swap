/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:54:37 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/19 15:55:49 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_put_stack(t_stack stack_a, t_stack stack_b)
{
	ssize_t	i;

	i = 0;
	printf(BYEL "\n\t[A]" BRED "\t[B]\n" RESET);
	while (i <= *stack_a.last_i || i <= *stack_b.last_i)
	{
		if (i <= *stack_a.last_i)
			printf(YEL "\t[%d]" RESET, stack_a.tab.tab[i]);
		else
			printf("\t");
		if (i <= *stack_b.last_i)
			printf(RED "\t[%d]" RESET, stack_b.tab.tab[i]);
		printf("\n");
		i++;
	}
}

void	put_stack(t_stack stack_a, t_stack stack_b)
{
	if (DEBUG)
	{
		if (stack_a.name == 'a')
			p_put_stack(stack_a, stack_b);
		else
			p_put_stack(stack_b, stack_a);
	}
}

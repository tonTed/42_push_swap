/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _put_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:54:37 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/29 11:20:05 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_put_stack(t_stacks stacks)
{
	ssize_t	i;

	i = 0;
	printf(BYEL "\n\t[A]" BRED "\t[B]\n" RESET);
	while (i <= *stacks.sa->last_i || i <= *stacks.sb->last_i)
	{
		if (i <= *stacks.sa->last_i)
			printf(YEL "\t[%d]" RESET, stacks.sa->tab.tab[i]);
		else
			printf("\t");
		if (i <= *stacks.sb->last_i)
			printf(RED "\t[%d]" RESET, stacks.sb->tab.tab[i]);
		printf("\n");
		i++;
	}
}

void	put_stack(t_stacks stacks)
{
	if (DEBUG)
		p_put_stack(stacks);
}

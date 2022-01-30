/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _put_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:54:37 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/30 11:15:35 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_put_stack(t_stacks s)
{
	ssize_t	i;

	i = 0;
	printf(BYEL "\n\t[A]" BRED "\t[B]\n" RESET);
	while (i <= s.a->i_end || i <= s.b->i_end)
	{
		if (i <= s.a->i_end)
			printf(YEL "\t[%d]" RESET, s.a->tab[i]);
		else
			printf("\t");
		if (i <= s.b->i_end)
			printf(RED "\t[%d]" RESET, s.b->tab[i]);
		printf("\n");
		i++;
	}
}

void	put_stack(t_stacks s)
{
	if (DEBUG)
		p_put_stack(s);
}

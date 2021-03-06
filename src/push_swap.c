/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2022/02/08 09:43:29 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_algo(t_stacks s)
{
	if (s.a->i_end == 1)
		swap(s.a);
	else if (s.a->i_end == 2)
		algo_3(s);
	else if (s.a->i_end < 5)
		algo_5(s);
	else
		algo_big(s);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	s = create_stacks(argv, argc);
	if (ft_issorted(s.a->tab, s.a->i_end + 1))
	{
		freestack(s);
		return (EXIT_SUCCESS);
	}
	manage_algo(s);
	put_stack(s);
	freestack(s);
	return (EXIT_SUCCESS);
}

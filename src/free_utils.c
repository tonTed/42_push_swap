/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:51:31 by tonted            #+#    #+#             */
/*   Updated: 2022/02/05 21:21:00 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeexit(char ***tabstr, int **tab, char *message)
{
	if (tabstr)
		ft_freetabstr(tabstr);
	if (tab)
		ft_freetabint(tab);
	ft_errormess_fd(STDERR_FILENO, message);
	if (*message)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	freestack(t_stacks s)
{
	free(s.a->tab);
	free(s.b->tab);
	free(s.a);
	free(s.b);
	free(s.max_sort);
}

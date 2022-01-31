/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:51:31 by tonted            #+#    #+#             */
/*   Updated: 2022/01/28 09:50:14 by tblanco          ###   ########.fr       */
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

void	freestack(t_stacks stacks)
{
	free(stacks.sa->tab.tab);
	free(stacks.sa->last_i);
	free(stacks.sb->tab.tab);
	free(stacks.sb->last_i);
	free(stacks.big_sort);
}

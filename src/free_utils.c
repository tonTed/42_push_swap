/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:51:31 by tonted            #+#    #+#             */
/*   Updated: 2022/01/25 19:38:59 by tonted           ###   ########.fr       */
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

void	freestack(t_stack sa, t_stack sb)
{
	free(sa.tab.tab);
	free(sa.last_i);
	free(sb.tab.tab);
	free(sb.last_i);
}

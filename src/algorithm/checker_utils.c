/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:08:11 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/19 16:08:22 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if is the bigger in the tab
bool	is_bigger_tab(int *tab, ssize_t len, int num)
{
	ssize_t	i;

	i = 0;
	while (i < len)
		if (tab[i++] > num)
			return (false);
	return (true);
}

// check if is the bigger in the tab
bool	is_smaller_tab(int *tab, ssize_t len, int num)
{
	ssize_t	i;

	i = 0;
	while (i < len)
		if (tab[i++] < num)
			return (false);
	return (true);
}

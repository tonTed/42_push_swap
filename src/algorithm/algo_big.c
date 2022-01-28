/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:38:59 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/28 11:51:14 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

input : 2 5 4 1 8 0 6 3 9 7
smaller = 0
i_last = 9 
index to push -> (i_last + 1) / 2 = 5
number to push > smaller + index to push - 1 -> 0 + 5  - 1 = 4

sb : 2 5 4 1 8 0 6 3 9 7

*/

void	first_push(t_stacks stacks)
{
	size_t	med;
	size_t	smaller;

	med = get_med(*stacks.sa);
	smaller = get_smaller(*stacks.sa);
	while ()
}



void	algo_big(t_stacks stacks)
{
	first_push(stacks);
}
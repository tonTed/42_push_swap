/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:24:33 by tonted            #+#    #+#             */
/*   Updated: 2021/12/25 22:32:13 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdbool.h>
// #include <stdio.h>

bool	ft_issorted(int *tab, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] > tab[i + 1] || tab[len - 1] < tab[len - 2])
			return (true);
		i++;
		len--;
	}
	return (false);
}

/*
int main()
{
	int tab[] = {1, 2, 5, 4};
	printf("%d\n", ft_issorted(tab, 4));
}
*/

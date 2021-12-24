/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2021/12/23 20:18:13 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(int argc, char **argv)
{
	printf("Hello %s\n", argv[0]);
	char	**args;
	int		i;
	
	if(argc < 2)
		return(EXIT_SUCCESS);
	else if (argc == 2)
	{
		args = ft_split(argv[1], SPACE);
		ft_puttabstr_fd(args, 1);
	}
	else
	{
		args = (char**)malloc(sizeof(char*) * argc);
		i = 0;
		while (i < (argc - 1))
		{
			printf("%s\n", argv[i + 1]);
			i++;
		}
	}
	return(EXIT_SUCCESS);
}

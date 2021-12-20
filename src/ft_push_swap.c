/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:59:40 by tblanco           #+#    #+#             */
/*   Updated: 2021/12/20 14:35:26 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
}

static void	check_number(char *nb, char **tab)
{
	if(*nb == '-' || *nb == "+" || ft_isdigit(*nb))
		nb++;
	while(*nb)
	{
		if(!(ft_isdigit(*nb)))
		{
			free(tab);
			ft_error();
		}
		nb++;
	}
}

static void check_input(int argc, char **argv)
{
	char	**args;
	int		i;
	
	if(argc < 2)
		exit(1);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = (char **)malloc(sizeof(char*) * (argc));
		if(!args)
			exit(1);
		i = 0;
		while (argc-- > 1)
		{
			args[i] = argv[i + 1];
			i++;
		}
	}
	ft_puttabstr_fd(args, 1);
}

int main(int argc, char **argv)
{
	
	printf("Hello %s\n", argv[0]);
	check_input(argc, argv);
	
	int i = 0;
	while (argc-- > 1)
	{
		printf("%p\n", argv[i + 1]);
		i++;
	}
	return 0;
}

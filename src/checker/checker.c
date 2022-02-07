/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:21:17 by tonted            #+#    #+#             */
/*   Updated: 2022/02/05 20:42:16 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}

int	move(t_stacks s, char *op)
{
	if (!ft_strncmp("sa", op, ft_strlen(op)))
		swap(s.a);
	else if (!ft_strncmp("sb", op, ft_strlen(op)))
		swap(s.b);
	else if (!ft_strncmp("ss", op, ft_strlen(op)))
		sswap(s.a, s.b);
	else if (!ft_strncmp("ra", op, ft_strlen(op)))
		rotate(s.a);
	else if (!ft_strncmp("rb", op, ft_strlen(op)))
		rotate(s.b);
	else if (!ft_strncmp("rr", op, ft_strlen(op)))
		rrotate(s.a, s.b);
	else if (!ft_strncmp("rra", op, ft_strlen(op)))
		rev_rotate(s.a);
	else if (!ft_strncmp("rrb", op, ft_strlen(op)))
		rev_rotate(s.b);
	else if (!ft_strncmp("rrr", op, ft_strlen(op)))
		rev_rrotate(s.a, s.b);
	else if (!ft_strncmp("pb", op, ft_strlen(op)))
		push(s.a, s.b);
	else if (!ft_strncmp("pa", op, ft_strlen(op)))
		push(s.b, s.a);
	else
		return (1);
	return (0);
}

int	readlines(t_stacks s)
{
	char	buffer[4];
	size_t	i;
	char	c;

	i = 0;
	while (42)
	{
		if (!read(0, &c, 1))
			return (0);
		if (c == '\n')
		{
			buffer[i] = 0;
			if (move(s, buffer))
				return (error());
			i = 0;
		}
		else
			buffer[i++] = c;
		if (i > 3)
			return (error());
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	s;

	s = create_stacks(argv, argc);
	if (!readlines(s))
	{
		if (ft_issorted(s.a->tab, s.a->i_end + 1) && s.b->i_end == -1)
			ft_putstr_fd("OK\n", STDOUT_FILENO);
		else
			ft_putstr_fd("KO\n", STDOUT_FILENO);
	}
	freestack(s);
	return (EXIT_SUCCESS);
}

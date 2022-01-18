/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:25:04 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/18 14:46:45 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct s_tabint
{
	int		*tab;
	size_t	size;
}				t_tabint;

typedef struct s_stack
{
	t_tabint	tab;
	ssize_t		*last_i;
	char		name;
}				t_stack;

/* manage input */
char		**create_tabstr(char **argv, int argc);
t_tabint	create_tabint(char **tabstr);
t_stack		create_stack(t_tabint tab, bool empty, char name);

void		freeexit(char ***tabstr, int **tab, char *message);

/* operations functions */
void		print_op(char *op, char stack);
void		move_down(t_stack stack);
void		move_up(t_stack stack);
void		move_down(t_stack stack);
void		swap(t_stack stack);
void		sswap(t_stack stack_1, t_stack stack_2);
void		push(t_stack src, t_stack dst);
void		rotate(t_stack stack);
void		rrotate(t_stack stack_1, t_stack stack_2);

# include <stdio.h>
#endif
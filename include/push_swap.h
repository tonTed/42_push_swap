/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:25:04 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/26 09:21:11 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# define DEBUG 1 

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
t_tabint	create_tab(char **argv, int argc);
t_stack		create_stack(t_tabint tab, bool empty, char name);
int			*tab_convert(int *tab, size_t len);

void		freeexit(char ***tabstr, int **tab, char *message);
void		freestack(t_stack sa, t_stack sb);

void		algorithm(t_stack stack_a, t_stack stack_b);
void		put_stack(t_stack stack_a, t_stack stack_b);

/* operations functions */
void		print_op(char *op, char stack);
void		move_down(t_stack stack);
void		move_up(t_stack stack);
void		swap(t_stack stack);
void		sswap(t_stack stack_1, t_stack stack_2);
void		push(t_stack src, t_stack dst);
void		rotate(t_stack stack);
void		rrotate(t_stack stack_1, t_stack stack_2);
void		rev_rotate(t_stack stack);
void		rev_rrotate(t_stack stack_1, t_stack stack_2);

void		algo_3(t_stack sa);
void		algo_5(t_stack sa, t_stack sb);

# include <stdio.h>
#endif
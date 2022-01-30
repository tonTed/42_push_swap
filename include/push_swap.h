/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:25:04 by tblanco           #+#    #+#             */
/*   Updated: 2022/01/30 11:40:54 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# define DEBUG 1 

typedef struct s_stack
{
	int		*tab;
	ssize_t	i_end;
	char	name;
}				t_stack;

typedef struct s_stacks
{
	t_stack		*a;
	t_stack		*b;
}				t_stacks;


/* manage input */
t_stacks	create_stacks(char **argv, int argc);
int			*tab_convert(int *tab, size_t len);

/* free functions */
void		freeexit(char ***tabstr, int **tab, char *message);
void		freestack(t_stacks stacks);

/* algorithm functions*/
void		algo_3(t_stack sa);
void		algo_5(t_stacks stacks);
void		algo_big(t_stacks stacks);
int			get_smaller(t_stack stack);
int			get_med(t_stack stack);
bool		to_swap(t_stack s1, t_stack s2);


size_t		where_is_bigger(t_stack stack);
ssize_t		is_numbers(t_stack stack, int nb);
bool		is_number(t_stack stack, int nb);
void		sort_to_a(t_stack src, t_stack dst);
void		push_next(t_stack src, t_stack dst, int med);
void		r_push_next(t_stack src, t_stack dst, int med);

/* operations functions */
void		print_op(char *op, char stack);
void		move_down(t_stack stack);
void		move_up(t_stack stack);
void		swap(t_stack stack);
void		sswap(t_stack stack_1, t_stack stack_2);
void		push(t_stack *src, t_stack *dst);
void		rotate(t_stack stack);
void		rrotate(t_stack stack_1, t_stack stack_2);
void		rev_rotate(t_stack stack);
void		rev_rrotate(t_stack stack_1, t_stack stack_2);

/* DEBUG functions */
void		put_stack(t_stacks stacks);

# include <stdio.h>
#endif
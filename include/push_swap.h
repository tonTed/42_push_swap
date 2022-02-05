/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:25:04 by tblanco           #+#    #+#             */
/*   Updated: 2022/02/05 09:51:05 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# define DEBUG 0

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
	int			*max_sort;
	int 		*max_flag;
}				t_stacks;


/* manage input */
t_stacks	create_stacks(char **argv, int argc);
int			*tab_convert(int *tab, size_t len);

/* free functions */
void		freeexit(char ***tabstr, int **tab, char *message);
void		freestack(t_stacks stacks);

/* algorithm functions*/
void		algo_3(t_stack *sa);
void		algo_5(t_stacks stacks);
void		algo_big(t_stacks stacks);
int			get_smaller(t_stack stack);
int			sort_to_a(t_stacks s);
void		sort_b(t_stacks s, int min);
void		push_to_b(t_stacks s, int min, int max);

/* optimization functions */
void		o_rotate_b(t_stacks s, int med);
void		opti_sswap(t_stacks s);
ssize_t		next_to_push_to_a(t_stacks s);

/* getters */
int		get_max(t_stack s);
int		get_min(t_stack s);
int		get_med(t_stack s);
ssize_t	get_index(int nb, t_stack s);

/* utils algo */
bool	is_in_tab(int nb, t_stack s);
bool	is_between(int nb, int min, int max);
bool	range_in_tab(t_stack s, int min, int max);

/* operations functions */
void	print_op(char *op, char stack);
void	move_down(t_stack *s);
void	move_up(t_stack *s);
void	swap(t_stack *stack);
void	sswap(t_stack *stack_1, t_stack *stack_2);
void	push(t_stack *src, t_stack *dst);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack_1, t_stack *stack_2);
void	rev_rotate(t_stack *stack);
void	rev_rrotate(t_stack *stack_1, t_stack *stack_2);

/* DEBUG functions */
void		put_stack(t_stacks stacks);

# include <stdio.h>
#endif
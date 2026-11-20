/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/09 16:13:22 by tcloix           #+#    #+#              */
/*   Updated: 2026/11/20 20:42:43 by thdeglos        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node	t_node;

struct s_node
{
	int		content;
	int		index;
	t_node	*next;
	t_node	*prev;
};

typedef struct s_opts
{
	int	strategy;
	int	bench;
}	t_opts;

typedef struct s_op
{
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rs;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}	t_op;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
	size_t	size_a;
	size_t	size_b;
	t_op	ops;
}	t_stacks;

// utils
void	put_str(char *s);
void	bench_ops(t_op *o);
size_t	total_ops(t_op *o);
void	bench_print(t_stacks *s, double disorder, int strategy, int algo);
double	disordercheck(t_stacks *s);
int		has_duplicate(t_node *stack);
void	indexer(t_stacks *s);
int		listfiller(t_stacks *s, int argc, char **argv, t_opts *o);
int		parse_flags(int argc, char **argv, t_opts *o);
int		parse_int(const char *s, int *result);
int		print_error(void);

// small algo
void	small_algo(t_stacks *s);

// algo 1 --simple
void	algo1(t_stacks *s);

// algo 2 --medium
void	algo2(t_stacks *s);
size_t	searchlittle(const t_node *stack, size_t size);

// algo 3 --complex
void	algo3(t_stacks *s);

// swap operations
void	swap(t_node *tab);
void	sa(t_stacks *s);
void	sb(t_stacks *s);
void	ss(t_stacks *s);

// push operations
void	push(t_node **dst, size_t *sizedst, t_node **src, size_t *sizesrc);
void	pa(t_stacks *s);
void	pb(t_stacks *s);

// rotate operations
void	rotate(t_node *tab);
void	ra(t_stacks *s);
void	rb(t_stacks *s);
void	rs(t_stacks *s);

// reverse_rotate operations
void	reverserotate(t_node *tab);
void	rra(t_stacks *s);
void	rrb(t_stacks *s);
void	rrr(t_stacks *s);

#endif

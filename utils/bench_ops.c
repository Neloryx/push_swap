/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:59:13 by thdeglos          #+#    #+#             */
/*   Updated: 2026/11/20 20:11:00 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	put_count(char *name, size_t count, char *end)
{
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	ft_putnbr_fd((int) count, 2);
	write(2, end, ft_strlen(end));
}

static size_t	total_ops(t_op *o)
{
	return (o->sa + o->sb + o->ss + o->pa + o->pb + o->ra + o->rb
		+ o->rs + o->rra + o->rrb + o->rrs);
}

void	bench_ops(t_op *o)
{
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd((int) total_ops(o), 2);
	write(2, "\n[bench] ", 9);
	put_count("sa", o->sa, " ");
	put_count("sb", o->sb, " ");
	put_count("ss", o->ss, " ");
	put_count("pa", o->pa, " ");
	put_count("pb", o->pb, " ");
	write(2, "\n[bench] ", 9);
	put_count("ra", o->ra, " ");
	put_count("rb", o->rb, " ");
	put_count("rr", o->rs, " ");
	put_count("rra", o->rra, " ");
	put_count("rrb", o->rrb, " ");
	put_count("rrr", o->rrs, "\n");
}

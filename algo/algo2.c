/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo2.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/09 11:45:54 by tcloix           #+#    #+#              */
/*   Updated: 2026/11/13 16:11:27 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	searchbigindex(const t_node *stack, size_t size)
{
	const t_node	*node;
	size_t			i;
	size_t			big;
	int				big_index;

	i = 0;
	big = 0;
	node = stack;
	big_index = stack->index;
	while (i < size && node != NULL)
	{
		if (node->index > big_index)
		{
			big = i;
			big_index = node->index;
		}
		node = node->next;
		i++;
	}
	return (big);
}

static size_t	chunksize(size_t size)
{
	size_t	chunk;

	chunk = 1;
	while (chunk * chunk < 3 * size)
		chunk++;
	return (chunk);
}

static void	part1(t_stacks *s, size_t chunk, size_t total)
{
	size_t	limit;
	size_t	tmp;

	limit = 0;
	while (s->size_a > 0)
	{
		limit += chunk;
		if (limit > total)
			limit = total;
		tmp = s->size_a;
		while (tmp > 0)
		{
			if ((size_t) s->a->index < limit)
				pb(s);
			else
				ra(s);
			tmp--;
		}
	}
}

static void	part2(t_stacks *s)
{
	size_t	big;
	size_t	i;

	while (s->size_b > 0)
	{
		big = searchbigindex(s->b, s->size_b);
		i = 0;
		if (big <= s->size_b / 2)
		{
			while (i < big)
			{
				rb(s);
				i++;
			}
		}
		else
		{
			while (i < s->size_b - big)
			{
				rrb(s);
				i++;
			}
		}
		pa(s);
	}
}

void	algo2(t_stacks *s)
{
	size_t	total;
	size_t	chunk;

	if (s == NULL)
		return ;
	total = s->size_a;
	if (total < 2)
		return ;
	chunk = chunksize(total);
	part1(s, chunk, total);
	part2(s);
}

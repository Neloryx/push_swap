/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:39:38 by thdeglos          #+#    #+#             */
/*   Updated: 2026/11/20 20:08:50 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	max_bits(size_t n)
{
	size_t	bits;

	bits = 0;
	while (((n - 1) >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass(t_stacks *s, size_t bit)
{
	size_t	i;
	size_t	n;

	n = s->size_a;
	i = 0;
	while (i < n)
	{
		if (((s->a->index >> bit) & 1) == 0)
			pb(s);
		else
			ra(s);
		i++;
	}
	while (s->size_b > 0)
		pa(s);
}

void	algo3(t_stacks *s)
{
	size_t	bit;
	size_t	bits;

	if (s == NULL || s->size_a < 2)
		return ;
	bits = max_bits(s->size_a);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(s, bit);
		bit++;
	}
}

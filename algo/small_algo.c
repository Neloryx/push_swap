/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:19:45 by tcloix            #+#    #+#             */
/*   Updated: 2026/11/20 20:28:13 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *s, int a, int b, int c)
{
	if (a > b && b < c && a < c)
		sa(s);
	else if (a > b && b > c)
	{
		sa(s);
		rra(s);
	}
	else if (a > b && a > c && b < c)
		ra(s);
	else if (a < b && b > c && a < c)
	{
		sa(s);
		ra(s);
	}
	else if (a < b && a > c)
		rra(s);
}

static void	push_little_to_b(t_stacks *s)
{
	size_t	little;
	size_t	i;

	little = searchlittle(s->a, s->size_a);
	i = 0;
	if (little <= s->size_a / 2)
	{
		while (i++ < little)
			ra(s);
	}
	else
	{
		while (i++ < s->size_a - little)
			rra(s);
	}
	pb(s);
}

void	small_algo(t_stacks *s)
{
	int	a;
	int	b;
	int	c;

	if (s == NULL || s->size_a < 2)
		return ;
	if (s->size_a == 2)
	{
		if (s->a->content > s->a->next->content)
			sa(s);
		return ;
	}
	while (s->size_a > 3)
		push_little_to_b(s);
	a = s->a->content;
	b = s->a->next->content;
	c = s->a->next->next->content;
	sort_three(s, a, b, c);
	while (s->size_b > 0)
		pa(s);
}

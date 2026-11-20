/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo1.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 12:35:34 by tcloix           #+#    #+#              */
/*   Updated: 2026/11/13 16:34:52 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	searchlittle(const t_node *stack, size_t size)
{
	const t_node	*node;
	size_t			i;
	size_t			little;
	int				little_value;

	if (stack == NULL)
		return (0);
	i = 0;
	little = 0;
	node = stack;
	little_value = stack->content;
	while (i < size && node != NULL)
	{
		if (node->content < little_value)
		{
			little = i;
			little_value = node->content;
		}
		node = node->next;
		i++;
	}
	return (little);
}

void	algo1(t_stacks *s)
{
	size_t	little;
	int		i;

	while (s->size_a > 0)
	{
		i = -1;
		little = searchlittle(s->a, s->size_a);
		if (s->size_a / 2 >= little)
		{
			while (++i < (int) little)
				ra(s);
		}
		else
		{
			while (++i < (int)(s->size_a - little))
				rra(s);
		}
		pb(s);
	}
	while (s->size_b > 0)
		pa(s);
}

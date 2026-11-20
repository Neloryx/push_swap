/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorderchecker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:52:06 by thdeglos          #+#    #+#             */
/*   Updated: 2026/11/13 20:22:27 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	count_errors(t_node *node, size_t *total)
{
	t_node	*next;
	size_t	errors;

	errors = 0;
	while (node != NULL)
	{
		next = node->next;
		while (next != NULL)
		{
			(*total)++;
			if (node->content > next->content)
				errors++;
			next = next->next;
		}
		node = node->next;
	}
	return (errors);
}

double	disordercheck(t_stacks *s)
{
	size_t	errors;
	size_t	total;

	if (s == NULL || s->size_a < 2)
		return (0);
	total = 0;
	errors = count_errors(s->a, &total);
	if (total == 0)
		return (0);
	return ((double) errors / (double) total);
}

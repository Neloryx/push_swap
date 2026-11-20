/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   duplicates.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: thdeglos <thdeglos@student.42lehavre.fr   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/12 23:37:36 by thdeglos         #+#    #+#              */
/*   Updated: 2026/11/13 16:12:43 by thdeglos        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_duplicate(t_node *stack)
{
	t_node	*other;

	while (stack != NULL)
	{
		other = stack->next;
		while (other != NULL)
		{
			if (other->content == stack->content)
			{
				return (1);
			}
			other = other->next;
		}
		stack = stack->next;
	}
	return (0);
}

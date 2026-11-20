/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:52:06 by tcloix            #+#    #+#             */
/*   Updated: 2026/11/13 20:21:36 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	indexer(t_stacks *s)
{
	t_node	*node;
	t_node	*other;

	if (s == NULL)
		return ;
	node = s->a;
	while (node != NULL)
	{
		node->index = 0;
		other = s->a;
		while (other != NULL)
		{
			if (other->content < node->content)
				node->index++;
			other = other->next;
		}
		node = node->next;
	}
}

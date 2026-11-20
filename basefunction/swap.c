/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 19:03:56 by tcloix            #+#    #+#             */
/*   Updated: 2026/11/13 20:22:28 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *tab)
{
	int	tmp_content;
	int	tmp_index;

	if (tab == NULL || tab->next == NULL)
		return ;
	tmp_content = tab->content;
	tmp_index = tab->index;
	tab->content = tab->next->content;
	tab->index = tab->next->index;
	tab->next->content = tmp_content;
	tab->next->index = tmp_index;
}

void	sa(t_stacks *s)
{
	swap(s->a);
	s->ops.sa++;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *s)
{
	swap(s->b);
	s->ops.sb++;
	write(1, "sb\n", 3);
}

void	ss(t_stacks *s)
{
	swap(s->a);
	swap(s->b);
	s->ops.ss++;
	write(1, "ss\n", 3);
}

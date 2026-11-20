/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcloix <tcloix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:57:19 by tcloix            #+#    #+#             */
/*   Updated: 2026/11/13 14:14:16 by tcloix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverserotate(t_node *tab)
{
	int	tmp_content;
	int	tmp_index;

	if (tab == NULL || tab->next == NULL)
		return ;
	while (tab->next)
	{
		tab = tab->next;
	}
	tmp_content = tab->content;
	tmp_index = tab->index;
	while (tab->prev)
	{
		tab->content = tab->prev->content;
		tab->index = tab->prev->index;
		tab = tab->prev;
	}
	tab->content = tmp_content;
	tab->index = tmp_index;
}

void	rra(t_stacks *s)
{
	reverserotate(s->a);
	s->ops.rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *s)
{
	reverserotate(s->b);
	s->ops.rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *s)
{
	reverserotate(s->a);
	reverserotate(s->b);
	s->ops.rrr++;
	write(1, "rrr\n", 4);
}

// int	main(void)
// {
// 	int	tab[5] =
// 	{
// 		1, 2, 3, 4, 5
// 	};
// 	size_t	i;

// 	reverserotate(tab, 5);
// 	i = 0;
// 	while (i < 5)
// 		printf("%d ", tab[i++]);
// 	printf("\n");
// 	return (0);
// }

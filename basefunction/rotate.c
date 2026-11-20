/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcloix <tcloix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 09:57:19 by tcloix            #+#    #+#             */
/*   Updated: 2026/11/13 14:15:01 by tcloix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node *tab)
{
	int	tmp_content;
	int	tmp_index;

	if (tab == NULL || tab->next == NULL)
		return ;
	tmp_content = tab->content;
	tmp_index = tab->index;
	while (tab->next)
	{
		tab->content = tab->next->content;
		tab->index = tab->next->index;
		tab = tab->next;
	}
	tab->content = tmp_content;
	tab->index = tmp_index;
}

void	ra(t_stacks *s)
{
	rotate(s->a);
	s->ops.ra++;
	write(1, "ra\n", 3);
}

void	rb(t_stacks *s)
{
	rotate(s->b);
	s->ops.rb++;
	write(1, "rb\n", 3);
}

void	rs(t_stacks *s)
{
	rotate(s->a);
	rotate(s->b);
	s->ops.rs++;
	write(1, "rr\n", 3);
}

// int	main(void)
// {
// 	int	tab[5] =
// 	{
// 		1, 2, 3, 4, 5
// 	};
// 	size_t	i;

// 	rotate(tab, 4);
// 	rotate(tab, 2);
// 	i = 0;
// 	while (i < 5)
// 		printf("%d ", tab[i++]);
// 	printf("\n");
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 11:40:10 by tcloix            #+#    #+#             */
/*   Updated: 2026/11/13 20:22:27 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dst, size_t *sizedst, t_node **src, size_t *sizesrc)
{
	t_node	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = node->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	node->prev = NULL;
	node->next = *dst;
	if (*dst != NULL)
		(*dst)->prev = node;
	*dst = node;
	(*sizedst)++;
	(*sizesrc)--;
}

void	pa(t_stacks *s)
{
	push(&s->a, &s->size_a, &s->b, &s->size_b);
	s->ops.pa++;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *s)
{
	push(&s->b, &s->size_b, &s->a, &s->size_a);
	s->ops.pb++;
	write(1, "pb\n", 3);
}

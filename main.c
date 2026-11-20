/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 23:38:53 by tcloix            #+#    #+#             */
/*   Updated: 2026/11/13 20:20:06 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_clear(t_node **stack)
{
	t_node	*next;

	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

static int	algorunner(t_stacks *s, double disorder, int strategy)
{
	if (s->size_a < 6 && disorder != 0)
	{
		small_algo(s);
		return (1);
	}
	if ((strategy == 1) || (strategy == 0 && disorder < 0.2))
	{
		if (disorder != 0)
			algo1(s);
		return (1);
	}
	else if ((strategy == 2) || (strategy == 0 && disorder < 0.5))
	{
		if (disorder != 0)
			algo2(s);
		return (2);
	}
	else if ((strategy == 3) || (strategy == 0 && 0.5 <= disorder))
	{
		if (disorder != 0)
			algo3(s);
		return (3);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	s;
	t_opts		o;
	int			algo;
	double		disorder;

	ft_bzero(&s, sizeof(t_stacks));
	if (!listfiller(&s, argc, argv, &o) || has_duplicate(s.a))
	{
		print_error();
		stack_clear(&s.a);
		stack_clear(&s.b);
		return (0);
	}
	disorder = disordercheck(&s);
	indexer(&s);
	algo = algorunner(&s, disorder, o.strategy);
	if (o.bench)
		bench_print(&s, disorder, o.strategy, algo);
	stack_clear(&s.a);
	stack_clear(&s.b);
	return (0);
}

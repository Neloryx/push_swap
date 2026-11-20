/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:07:38 by thdeglos          #+#    #+#             */
/*   Updated: 2026/11/20 20:11:58 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	put_str(char *s)
{
	write(2, s, ft_strlen(s));
}

static void	put_percent(double disorder)
{
	long	v;

	v = (long)(disorder * 10000 + 0.5);
	ft_putnbr_fd((int)(v / 100), 2);
	put_str(".");
	if (v % 100 < 10)
		put_str("0");
	ft_putnbr_fd((int)(v % 100), 2);
	put_str("%\n");
}

static void	put_strategy(int strategy, int algo)
{
	put_str("[bench] strategy: ");
	if (strategy == 0)
		put_str("Adaptive / ");
	else if (strategy == 1)
		put_str("Simple / ");
	else if (strategy == 2)
		put_str("Medium / ");
	else
		put_str("Complex / ");
	if (algo == 1)
		put_str("O(n^2)\n");
	else if (algo == 2)
		put_str("O(n*sqrt(n))\n");
	else
		put_str("O(n log n)\n");
}

void	bench_print(t_stacks *s, double disorder, int strategy, int algo)
{
	put_str("[bench] disorder: ");
	put_percent(disorder);
	put_strategy(strategy, algo);
	bench_ops(&s->ops);
}

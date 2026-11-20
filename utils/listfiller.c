/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfiller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:16:00 by tcloix            #+#    #+#             */
/*   Updated: 2026/11/13 20:21:34 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	stack_add_back(t_node **stack, int content)
{
	t_node	*node;
	t_node	*last;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (0);
	node->content = content;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	if (*stack == NULL)
		*stack = node;
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = node;
		node->prev = last;
	}
	return (1);
}

static void	split_clear(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

static int	append_values(t_stacks *s, char **tab)
{
	int	i;
	int	value;

	i = 0;
	while (tab[i] != NULL)
	{
		if (!parse_int(tab[i], &value))
		{
			return (0);
		}
		if (!stack_add_back(&s->a, value))
			return (0);
		s->size_a++;
		i++;
	}
	return (1);
}

static int	append_arg(t_stacks *s, char *arg)
{
	char	**tab;
	int		result;

	tab = ft_split(arg, ' ');
	if (tab == NULL)
		return (0);
	if (tab[0] == NULL)
	{
		split_clear(tab);
		return (0);
	}
	result = append_values(s, tab);
	split_clear(tab);
	return (result);
}

int	listfiller(t_stacks *s, int argc, char **argv, t_opts *o)
{
	int	i;

	i = parse_flags(argc, argv, o);
	if (i < 0)
	{
		return (0);
	}
	while (i < argc)
	{
		if (!append_arg(s, argv[i]))
			return (0);
		i++;
	}
	return (1);
}

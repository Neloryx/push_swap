/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:52:54 by thdeglos          #+#    #+#             */
/*   Updated: 2026/11/20 20:20:16 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_flag(char *arg, char *flag)
{
	size_t	len;

	len = ft_strlen(flag);
	return (ft_strncmp(arg, flag, len + 1) == 0);
}

static int	set_flag(char *arg, t_opts *o)
{
	if (is_flag(arg, "--simple"))
		o->strategy = 1;
	else if (is_flag(arg, "--medium"))
		o->strategy = 2;
	else if (is_flag(arg, "--complex"))
		o->strategy = 3;
	else if (is_flag(arg, "--adaptive"))
		o->strategy = 0;
	else if (is_flag(arg, "--bench"))
		o->bench = 1;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, t_opts *o)
{
	int	i;

	o->strategy = 0;
	o->bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!set_flag(argv[i], o))
			return (-1);
		i++;
	}
	return (i);
}

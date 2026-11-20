/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/15 13:34:40 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/20 12:01:00 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (i > 0 && s[i - 1] == c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static void	*free_tab(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

static char	**fill(char **tab, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			tab[j] = ft_substr(s, start, i - start);
			if (!tab[j])
				return (free_tab(tab, j));
			j++;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_calloc(countword(s, c) + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	return (fill(tab, s, c));
}

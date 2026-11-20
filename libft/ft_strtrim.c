/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strtrim.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/14 14:30:07 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/19 12:33:03 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c != set[i] && set[i])
	{
		i++;
	}
	if (c == set[i])
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (checkset(s1[start], set))
		start++;
	while (end > start && checkset(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}

// version sans substr
// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t	start;
// 	size_t	end;

// 	size_t	i;
// 	char	*final;
// 	if (!s1 || !set)
// 		return (NULL);
// 	i = 0;
// 	start = 0;
// 	end = ft_strlen(s1);
// 	while (checkset(s1[start], set))
// 		start++;
// 	while (end > start && checkset(s1[end - 1], set))
// 		end--;
// 	final = malloc(end - start + 1);
// 	if (final == NULL)
// 		return (NULL);
// 	while (start < end)
// 	{
// 		final[i] = s1[start];
// 		start++;
// 		i++;
// 	}
// 	final[i] = '\0';
// 	return (final);
// }

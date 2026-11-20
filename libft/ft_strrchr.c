/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/13 14:25:31 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/20 12:44:07 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s[i] == c && !s[i])
		return ((char *)(s + i));
	else
		i--;
	while (i >= 0 && s[i] != (char)(c))
	{
		if (!s[i])
			return (NULL);
		i--;
	}
	if (i < 0)
		return (NULL);
	return ((char *)(s + i));
}

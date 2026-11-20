/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/11 15:25:38 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/20 12:50:31 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*source;
	size_t				i;

	source = s;
	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if (source[i] == (unsigned char) c)
		{
			return ((void *) & source[i]);
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memmove.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/11 15:08:18 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/19 15:32:57 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*des;
	const unsigned char	*source;
	size_t				i;

	des = dest;
	source = src;
	i = 0;
	if (dest <= src)
	{
		while (i < n)
		{
			des[i] = source[i];
			i++;
		}
		return (dest);
	}
	else
	{
		while (n > 0)
		{
			n--;
			des[n] = source[n];
		}
		return (dest);
	}
}

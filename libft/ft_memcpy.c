/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memcpy.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/11 14:55:25 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/19 15:31:10 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*des;
	const unsigned char	*source;
	size_t				i;

	des = dest;
	source = src;
	i = 0;
	while (i < n)
	{
		des[i] = source[i];
		i++;
	}
	return (dest);
}

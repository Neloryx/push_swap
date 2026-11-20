/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/11 15:45:39 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/20 13:05:36 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && n == 0)
		return (NULL);
	if (!little)
		return (NULL);
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < n && little[j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *) & big[i]);
		i++;
	}
	return (NULL);
}

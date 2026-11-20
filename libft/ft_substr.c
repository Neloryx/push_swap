/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_substr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/14 13:54:40 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/20 12:16:42 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	else if (len > s_len - start)
		len = s_len - start;
	final = malloc(sizeof(char) * (len + 1));
	if (final == NULL)
		return (NULL);
	ft_memmove(final, s + start, len);
	final[len] = '\0';
	return (final);
}
